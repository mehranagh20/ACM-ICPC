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

vector<ll> graph;
ll mx, num, n;

void solve(int i, ll used, ll depth) {
    if(used == (1LL << n) - 1) {
        mx = max(mx, depth), num++;
    }
    for(ll j = i; j < n; j++) if(!(used & (1LL << j))) {
        solve(j + 1, used | graph[j], depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        graph.resize(n, 0);
        for(ll i = 0; i < n; i++) graph[i] = 1LL << i;
        for(int i = 0; i < m; i++) {
            ll a, b; cin >> a >> b;
            graph[a] |= (1LL << b);
            graph[b] |= (1LL << a);
        }
        mx = num = 0;
        solve(0, 0, 0);
        cout << num << endl << mx << endl;
    }


    return 0;
}
