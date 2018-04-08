//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

int main() {
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, m, l; cin >> n >> m >> l;
        cin.get();
        map<string, ii> mp;
        vector<pair<int, string>> v;
        for(int i = 0; i < l; i++) {
            string str, name;
            getline(cin, str);
            int a, b;
            char tmp;
            stringstream ss(str);
            getline(ss, name, ':');
            ss >> a >> tmp >> b;
            mp[name] = ii(a, b);
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            vi cost(n + 1, inf); cost[n] = 0;
            for(int i = n - 1; i >= m; i--) {
                cost[i] = min(cost[i + 1] + it->second.first, cost[i]);
                if(i * 2 <= n) {
                    cost[i] = min(cost[i * 2] + it->second.second, cost[i]);
                }
                if(i * 2 + 1 <= n) cost[i] = min(cost[i], cost[i * 2 + 1] + it->second.second);
            }
            v.push_back(pair<int, string>(cost[m], it->first));
        }
        sort(v.begin(), v.end());
        cout << "Case " << i << endl;
        for(auto &e : v) cout << e.second << " " << e.first << endl;
    }

    return 0;
}
