//In The Name Of God
#include <bits/stdc++.h>

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

#define inf 1000000000
#define eps 1e-9

double pi = acos(-1.);

double degToRad(double theta){ return theta * pi / 180.0; }

dd rotate(dd p, double theta) {
    double rad = degToRad(theta);
    return dd(p.first * cos(rad) - p.second * sin(rad),
              p.first * sin(rad) + p.second * cos(rad));
}

dd circumCircle(dd p1, dd p2, dd p3){
    double x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
    double x3 = p3.first, y3 = p3.second;

    double a1 = 2 * (x2 - x1), b1 = 2 * (y2 - y1), c1 = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
    double a2 = 2 * (x3 - x1), b2 = 2 * (y3 - y1), c2 = x3 * x3 + y3 * y3 - x1 * x1 - y1 * y1;
    double d = a1 * b2 - b1 * a2;

    dd ctr;
    ctr.first = (c1 * b2 - b1 * c2) / d;
    ctr.second = (a1 * c2 - c1 * a2) / d;
    return ctr;
}

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 1;
    while(cin >> n && n) {
        vdd triangle(3);
        for(auto &e : triangle) cin >> e.first >> e.second;
        dd a = triangle[0], b = triangle[1], c = triangle[2];
        dd center = circumCircle(a, b, c);
        a.first -= center.first, a.second -= center.second;
        double minx = a.first, miny = a.second, maxx = a.first, maxy = a.second, deg = 360. / n;
        for(int i = 0; i < n - 1; i++) {
            dd p = rotate(a, deg);
            minx = min(minx, p.first), miny = min(miny, p.second);
            maxx = max(maxx, p.first), maxy = max(maxy, p.second);
            a = p;
        }
        cout << "Polygon " << tc++ << ": " << fixed << setprecision(3) << (maxx - minx) * (maxy - miny) << endl;
    }

    return 0;
}
