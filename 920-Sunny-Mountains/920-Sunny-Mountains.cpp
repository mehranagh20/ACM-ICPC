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
typedef pair<dd, double> ddd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

void pointsToLine(dd p1, dd p2, ddd &l) {
    double &a = l.first.first, &b = l.first.second, &c = l.second;
    double &x1 = p1.first, &y1 = p1.second, &x2 = p2.first;

    if (fabs(x1 - x2) < eps) // vertical line is fine
        a = 1.0, b = 0.0, c = -x1;

    else {
        a = -(y1 - p2.second) / (x1 - x2);
        b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        c = -(a * x1) - y1;
    }
}

double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        double ans = 0;
        vdd coors(n);
        for(auto &e : coors) cin >> e.first >> e.second;
        sort(coors.begin(), coors.end());
        for(int i = 0; i < n - 1; i++) {
            // finding maximum y from here to end;
            double mx_y = 0;
            for(int j = i + 1; j < n; j++) {
                mx_y = max(mx_y, coors[j].second);
                if(mx_y >= coors[i].second) break;
            }
            if(mx_y < coors[i].second) { // then we have sth to add.
                ddd line; pointsToLine(coors[i], coors[i + 1], line);
                dd p; p.second = mx_y;
                p.first = -(mx_y + line.second) / line.first.first;
                ans += dist(coors[i], p);
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }


    return 0;
}
