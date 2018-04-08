//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
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
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

ll n = 3, MOD = 1e9 + 7; // change n and MOD to meet your requirements

vvi matMul(vvi &a, vvi &b) {
    vvi c(n, vi(n, 0));
    int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (k = 0; k < n; k++) {
                c[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
                c[i][j] %= MOD;
            }
    return c;
}

vvi matPow(vvi base, ll p) {
    vvi ans(n, vi(n, 0)); int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            ans[i][j] = (i == j);
    while (p) {
        if (p & 1)
            ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

vvi org = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
vi block = {0, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    ll o, m; cin >> o >> m;
    viii obs;
    for(int i = 0; i < o; i++) {
        ll a, l, r; cin >> a >> l >> r;
        obs.pb(iii(ii(l - 1, -1), a));
        obs.pb(iii(ii(r, 1), a));
    }
    vi isBlc = {0, 0, 0};
    vvi ans(3, vi(3, 0));
    ans[0] = {0, 1, 0};
    ll cur = 1;
    sort(obs.begin(), obs.end());
    for(auto &e: obs) {
        if(e.F.F < cur) {
            isBlc[e.S - 1] -= e.F.S;
            continue;
        }
        vvi curMat(3, vi(3));
        for(int i = 0; i < 3; i++) {
            vi toc;
            if (isBlc[i]) toc = block;
            else toc = org[i];
            for(int j = 0; j < 3; j++)
                curMat[j][i] = toc[j];
        }

        vvi c = matPow(curMat, e.F.F - cur + (cur > 1));
        ans = matMul(ans, c);
        cur = e.F.F + 1;
        isBlc[e.S - 1] -= e.F.S;
    }
    vvi curMat(3, vi(3));
    for(int i = 0; i < 3; i++) {
        vi toc;
        if (isBlc[i]) toc = block;
        else toc = org[i];
        for(int j = 0; j < 3; j++)
            curMat[j][i] = toc[j];
    }

    vvi c = matPow(curMat, m - cur + 1);
    ans = matMul(ans, c);


    cout << ans[0][1] << endl;


    return 0;
}
