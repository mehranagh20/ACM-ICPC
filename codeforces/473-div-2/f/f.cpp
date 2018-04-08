//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000 + 1
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vi nms(n), ans(q, 0);
    for(auto &e: nms) cin >> e;
    vvii qs(n);
    bitset<1LL << 22> vis; vis[0] = 1;
    vi cur = {0};
    for(int i = 0; i < q; i++) {
        int l, x; cin >> l >> x;
        qs[l - 1].push_back(ii(i, x));
    }
    ll cur_num = 1;
    for(int i = 0; i < n; i++) {
        ll a = nms[i];
        if(vis[a])
            cur_num = (cur_num * 2) % mod;
        else {
            int sz = cur.size();
            for (int j = 0; j < sz; ++j)
                cur.push_back(cur[j] ^ a), vis[cur[j] ^ a] = 1;
        }
        for(auto &e: qs[i])
            ans[e.F] = cur_num * vis[e.S];
    }

    for(auto &e: ans) cout << e << endl;




    return 0;
}