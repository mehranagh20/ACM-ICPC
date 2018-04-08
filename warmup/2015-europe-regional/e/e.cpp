//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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
vi match, vis;
// global variables
int Aug(int l, vvi &AdjList) {
// return 1 if an augmenting path is found
    if (vis[l]) return 0;
// return 0 otherwise
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
        int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList
        if (match[r] == -1 || Aug(match[r], AdjList)) {
            match[r] = l; return 1;
// found 1 matching
        } }
    return 0;
// no matching
}
// inside int main()
// build unweighted bipartite graph with directed edge left->right set
int main() {
    ll n;
    while(cin >> n) {
        int ind = 0;
        map<ll, ll > mp;
        vvi graph(3 * n + n + 10);
        vii nums;
        for (int i = 0; i < n; ++i) {
            ll a, b; cin >> a >> b;
            nums.push_back(ii(a, b));
            if(mp.find(a * b) == mp.end()) mp[a * b] = ind++;
            if(mp.find(a + b) == mp.end()) mp[a + b] = ind++;
            if(mp.find(a - b) == mp.end()) mp[a - b] = ind++;
            set<ll> st;
            st.insert(a + b);
            st.insert(a * b);
            st.insert(a - b);
            for(auto &e: st) graph[i].push_back(n + mp[e]), graph[n + mp[e]].push_back(i);

        }
        int MCBM = 0;
        match.assign(3 * n + 10 + n, -1);
        for (int l = 0; l < n; l++) {
            vis.assign(n * 3 + n + 10, 0);
            MCBM += Aug(l, graph);
        }
        if(MCBM != n) cout << "impossible" << endl;
        else {
            for (int i = 0; i < n; i++) {
                ll a = nums[i].first, b = nums[i].second;
                if(match[mp[a * b] + n] == i) cout << a << " * " << b << " = " << a * b << endl;
                else if(match[mp[a + b] + n] == i) cout << a << " + " << b << " = " << a + b << endl;
                else if(match[mp[a - b] + n] == i) cout << a << " - " << b << " = " << a - b << endl;
            }
        }
    }




    return 0;
}
