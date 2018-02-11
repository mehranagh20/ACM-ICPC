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

set<ii> prevv;
set<int> nvis;

int dfs(int a) {
    int cur = 1;
    nvis.erase(a);
    for(auto it = nvis.begin(); it != nvis.end();) {
        int x = *it;
        if(prevv.find(ii(a, x)) == prevv.end()) {
            cur += dfs(*it);
            it = nvis.upper_bound(x);
        }
        else it++;
    }
    return cur;
}


int main() {
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        prevv.insert(ii(a, b)), prevv.insert(ii(b, a));
    }
    for(int i = 0; i < n; i++) {
        nvis.insert(i);
    }

    vi ans;
    for(int i = 0; i < n; i++) {
        if(nvis.count(i)) ans.push_back(dfs(i));
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl << ans[0];
    for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];



    return 0;
}