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

dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }
double cross(dd a, dd b) { return a.first * b.second - a.second * b.first; }
bool collinear(dd p, dd q, dd r) { return fabs(cross(toVec(p, q), toVec(p, r))) < eps; }

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n; cin >> n;
        set<dd> s;
        vdd ps;
        for(int i = 0; i < n; i++) {
            double a, b; cin >> a >> b;
            if(s.find(dd(a, b)) != s.end()) continue;
            s.insert(dd(a, b));
            ps.push_back(dd(a, b));
        }
        cout << "Data set #" << i << " ";
        if(s.size() == 1) cout << "contains a single gnu.\n";
        else {
            int mx = 0;
            for(int e = 0; e < ps.size(); e++) for(auto ee = e + 1; ee < ps.size(); ee++) {
                int cur = 0;
                for(auto eee = ee + 1; eee < ps.size(); eee++) if(collinear(ps[e], ps[ee], ps[eee])) cur++;
                mx = max(mx, cur);
            }
            cout << "contains " << s.size() << " gnus, out of which a maximum of " << mx + 2 << " are aligned.\n";
        }
    }


    return 0;
}
