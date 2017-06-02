#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define inf 100000000
#define eps 1e-9
#define pi acos(-1)

typedef pair<double, double> dd;

double l, w;
dd c1, c2, p;
void f(double r1, double r2){
    double R = sqrt(w * w + l * l);
    double x1 = 0, y1 = l, x2 = w, y2 = 0;

    double co1 = (r1 * r1 - r2 * r2) / (2 * R * R);
    double co2 = sqrt(2 * (r1 * r1 + r2 * r2) / (R * R) -
                         pow((r1 * r1 - r2 * r2), 2) / pow(R, 4) - 1) / 2;

    c1.first = (x1 + x2) / 2 + co1 * (x2 - x1) + co2 * (y2 - y1);
    c1.second = (y1 + y2) / 2 + co1 * (y2 - y1) + co2 * (x1 - x2);


    c2.first = (x1 + x2) / 2 + co1 * (x2 - x1) - co2 * (y2 - y1);
    c2.second = (y1 + y2) / 2 + co1 * (y2 - y1) - co2 * (x1 - x2);
}

// converts 2 points to vector a->b
dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }

// dot product
double dot(dd a, dd b) { return (a.first * b.first + a.second * b.second); }

// norm of vector
double norm_sq(dd v) { return v.first * v.first + v.second * v.second; }

double radToDeg(double theta){ return theta * 180.0 / pi; }

double angle(dd a, dd o, dd b) {
    dd oa = toVec(o, a), ob = toVec(o, b);
    double ans =  acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
    return radToDeg(ans);
}

double degToRad(double theta){ return theta * pi / 180.0; }

double sectorArea(double r, double theta){ return (theta / 360.0) * (pi * r * r); }

// uses: degToRad -> points AND sectorArea -> circles
// Segment of a circle is defined as a region of the circle enclosed
// by a chord and an arc lying between the chord’s endpoints
double segmentArea(double r, double theta){
    return sectorArea(r, theta) - (r * r * sin(degToRad(theta)) / 2);
}

int main() {
    ios::sync_with_stdio(0);
    double r;
    while(cin >> l >> w >> r){
        double ans = pi * pow(r, 2) * 3 / 4;

        w = abs(w), l = abs(l);

        if(l == 0 || w == 0)
            ans = pi * (pow(r, 2));

        else if(r > l + w){
            ans += (pi * pow((r - l), 2)) / 4 + (pi * pow((r - w), 2)) / 4;
            f(r - l, r - w);

            if(c1.first > w && c1.second > l)
                p = c1;
            else
                p = c2;

            ans -= (p.first - w) * (p.second - l);


            double theta1 = angle(p, dd(0, l), dd(r - l, l));
            double area1 = segmentArea(r - l, theta1 * 2) / 2;

            double theta2 = angle(p, dd(w, 0), dd(w, r - w));
            double area2 = segmentArea(r - w, theta2 * 2) / 2;

            ans -= area1 + area2;


        }
        else {
            if(r > w)
                ans += pi * pow(r - w, 2) * 1 / 4;

            if (r > l)
                ans += pi * pow(r - l, 2) * 1 / 4;
        }

        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}
