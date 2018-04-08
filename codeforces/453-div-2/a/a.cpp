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
typedef vector<int> vi;
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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define S second
#define pb push_back
vi vis(200, 0);
vvi tel(200);
int m;

bool solve(int i, int b) {
    for (int j = i + 1; j <= b; ++j) {
        if(j == m) return true;
        for(auto &e: tel[j]) if(!vis[j]) {
                vis[j] = true;
                if(solve(j, e)) return true;
            }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        tel[a].push_back(b);
    }
    bool ans = false;
    for(auto &e: tel[0]) if(solve(0, e)) ans = true;
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}
