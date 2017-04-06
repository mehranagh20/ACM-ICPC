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

// to get the other center, reverse p1 and p2
// Determines the location of the centers (c1 and c2) of the two possible circles
// Given 2 points on the circle (p1 and p2) and radius r of the corresponding circle
bool circle2PtsRad(dd p1, dd p2, double r, dd &c) {
    double &x1 = p1.first, &y1 = p1.second, &x2 = p2.first, &y2 = p2.second;
    double d2 = pow((x1 - x2), 2) +  pow((y1 - y2), 2);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;

    double h = sqrt(det);
    c.first = (x1 + x2) / 2 + (y1 - y2) * h;
    c.second = (y1 + y2) / 2 + (x2 - x1) * h;
    return true; // to get the other center, reverse p1 and p2
}

// test point p relation to circle with c as center and r radius
// returns 0 -> inside, 1 -> border, 2 -> outside
int insideCircle(dd p, dd c, double r) {
    double dx = p.first - c.first, dy = p.second - c.second;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    return rSq - Euc > eps ? 0 : (fabs(rSq - Euc) < eps ? 1 : 2);
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        vdd points(n);
        for(auto &e : points) cin >> e.first >> e.second;
        double r; cin >> r;
        bool found = false;
        for(int i = 0; i < n && !found; i++) for(int j = 0; j < n && !found; j++) {
            if(i == j) continue;
            dd center;
            if(circle2PtsRad(points[i], points[j], r, center))
                for(int i = 0; i < n; i++) {
                    if(insideCircle(points[i], center, r) == 2) break;
                    if(i == n - 1) found = true;
                }
        }
        if(found) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }


    return 0;
}
