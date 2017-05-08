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

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, v; cin >> n >> v;
        set<string> st;
        vector<pair<ii, string>> items(n);
        map<string, vector<ii>> mp;
        for(int i = 0; i < n; i++) {
            string type, name;
            int val, qu; cin >> type >> name >> val >> qu;
            st.insert(type);
            mp[type].push_back(ii(val, qu));
            items[i].first.first = qu, items[i].first.second = val, items[i].second = type;
        }
        sort(items.begin(), items.end());
        int ans = -inf;
        for(int i = 0; i < n; i++) {
            int now = items[i].first.second, min_qu = items[i].first.first;
            for(auto e: st) {
                if(e != items[i].second) {
                    int now_val = inf;
                    for(auto &ee: mp[e]) if(ee.second >= min_qu && ee.first < now_val)
                        now_val = ee.first;
                    if(now_val == inf) {
                        now = inf;
                        break;
                    }
                    now += now_val;
                }
            }
            if(now <= v) ans = min_qu;
        }
        cout << ans << endl;
    }


    return 0;
}
