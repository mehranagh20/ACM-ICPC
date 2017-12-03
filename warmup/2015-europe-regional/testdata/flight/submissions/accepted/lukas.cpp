//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

struct Point3D {
    typedef double T;
    typedef Point3D P;
    typedef const P & R;
    T x, y, z;
    explicit Point3D(T x=T(), T y=T(), T z=T()) : x(x), y(y), z(z) { }
    bool operator==(R p) const { return x==p.x&&y==p.y&&z==p.z; }
    P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
    P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
    P operator-() { return P(-x, -y, -z); }
    P operator*(T d) const { return P(x*d, y*d, z*d); }
    P operator/(T d) const { return P(x/d, y/d, z/d); }
    T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
    P cross(R p) const {
        return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
    }
    T dist2() const { return x*x + y*y + z*z; } //distance^2
    double dist() const { return sqrt((double)dist2()); }
    P unit() const { return *this/(T)dist(); } //makes dist()=1
    //returns unit vector normal to *this and p
    P normal(P p) const { return cross(p).unit(); }
    T angle(P p) { return acos(dot(p)); }
};
ostream & operator<<(ostream & os, const Point3D & p) {
    os << "(" << p.x << "," << p.y << "," << p.z << ")";
    return os;
}

Point3D read_point()
{
    double x, y;
    scanf("%lf %lf", &x, &y);
    x *= M_PI / 180;
    y *= M_PI / 180;
    return Point3D(cos(x) * sin(y), cos(x) * cos(y), sin(x));
}
bool between(Point3D a, Point3D x, Point3D b)
{
    double two = x.angle(a) + x.angle(b);
    return abs(two - a.angle(b)) < 1e-6;
}
int main()
{
    int c; scanf("%d", &c);
    vector<vector<Point3D>> continents;
    rep(i,0,c)
    {
        int n; scanf("%d", &n);
        vector<Point3D> points;
        rep(j,0,n)
            points.push_back(read_point());
        points.push_back(points[0]);
        continents.push_back(points);
    }

    vector<Point3D> flight;
    int m; scanf("%d", &m);
    rep(l,0,m)
        flight.push_back(read_point());

    vector<double> events;
    double distance = 0;
    rep(i,0,m-1)
    {
        Point3D fn = flight[i + 1].normal(flight[i]);

        for (auto cont : continents)
        {
            for (int j = 0; j + 1 < (int)cont.size(); j++)
            {
                Point3D cn = cont[j + 1].normal(cont[j]);
                if (abs(fn.cross(cn).dist()) > 1e-6)
                {
                    Point3D intersect = fn.normal(cn);
                    if (between(flight[i], intersect, flight[i + 1]) &&
                        between(cont[j], intersect, cont[j + 1]))
                        events.push_back(flight[i].angle(intersect) + distance);
                    else if (between(flight[i], -intersect, flight[i + 1]) &&
                        between(cont[j], -intersect, cont[j + 1]))
                        events.push_back(flight[i].angle(-intersect) + distance);
                }
            }
        }
        distance += flight[i + 1].angle(flight[i]);
    }
    sort(events.begin(), events.end());
    assert(events.size() % 2 == 0);

    double water = 0;
    for (size_t j = 0; j + 1 < events.size(); j += 2)
        water += events[j + 1] - events[j];
    cout.precision(15);
    cout << distance * 6370 << " " << 100 * water / distance << endl;
}
