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
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back


ll toNum(char str[], int n) {
    ll num = 0, po = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '1')
            num += (1 << po);
        po++;
    }
    return num;
}

ll qu[1 << 13][101];
ll w[100000 * 5 + 100];
ll all[1 << 13];
ll vals[1 << 13];
char a[13];

int main() {
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    forn(i, n) scanf("%lld", &w[i]);
    forn(i, m) {
        scanf("%s", a);
        all[toNum(a, n)]++;
    }
    forn(i, 1 << n) forn(j, 102) qu[i][j] = 0;

    forn(tmp, 1 << n) {
            if(!vals[tmp])
            forn(k, n) if(!(tmp & (1 << k)))
                    vals[tmp] += w[n - k - 1];
        }

    forn(i, 1 << n) {
        forn(t, 1 << n) if (all[t]) {
                ll am = vals[i ^ t];
//                for (int j = n - 1; j >= 0; j--) {
//                    if (tmp[j] == e[j])
//                        am += w[j];
//                }
                if (am <= 100)
                    qu[i][am] += all[t];
            }

        forn(y, 101) if (y)
                qu[i][y] += qu[i][y - 1];
    }

    forn(i, q) {
        scanf("%s", a);
        int k; scanf("%d", &k);
        printf("%lld\n", qu[toNum(a, n)][k]);
    }

    return 0;
}