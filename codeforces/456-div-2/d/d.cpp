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

ll n, m, r, k;

vii moves = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

ll num(ll i, ll j) {
    i++, j++;
    ll f = min(n, i + r - 1) - max(r, i), s = min(m, j + r - 1) - max(r, j);
    return (f + 1) * (s + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> r >> k;
    ll tot = (n - r + 1) * (m - r + 1);
    int bi = n / 2, bj = m / 2;
    priority_queue<iii> q; q.push(iii(num(bi, bj), ii(bi, bj)));
    ull ans = 0;
    set<ii> s = {{bi, bj}};
    while(k--) {
        iii now = q.top(); q.pop();
        ans += now.first;
        int i = now.second.first, j = now.second.second;
        for(auto &e: moves) if(i + e.first >= 0 && i + e.first < n && j + e.second >= 0 && j + e.second < m) {
                if(s.count(ii(i + e.first, j + e.second)) == 0)
                    q.push(iii(num(i + e.first, j + e.second), ii(i + e.first, j + e.second))), s.insert(ii(i + e.first, j + e.second));
            }
    }
    cout << fixed << setprecision(10) << (double)ans / tot << endl;

    return 0;
}
