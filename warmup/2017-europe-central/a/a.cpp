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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    multiset<dd> ms;
    map<dd, int> mp;
    for(int i = 0; i < n; i++) {
        int e, x, y; cin >> e >> x >> y;
        if(e == 1) ms.insert(dd(x + abs(y), y)), mp[dd(x, y)] = i;
        else {
            auto it = ms.upper_bound(dd(x ,y));
            if(it == ms.end()) cout << -1 << endl;
            else {
                double xx = it->first - abs(it->second), yy = it->second, r = abs(it->second);
                if(r - dist(dd(xx, yy), dd(x, y)) > eps) {
                    cout << mp[dd(xx, yy)] + 1 << endl;
                    ms.erace(it);
                }
                else cout << -1 << endl;

            }
        }
    }


    return 0;
}
