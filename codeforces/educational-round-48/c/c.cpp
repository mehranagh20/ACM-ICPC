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

#define forn(i, n) for (int i = 0; i < n; i++)
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

const int MX = 3 * 1e5 + 100;

ll gr[2][MX];
ll frr[MX], srl[MX], frl[MX], srr[MX], smr[MX], smc[MX];

int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    forn(i, n) cin >> gr[0][i];
    forn(i, n) cin >> gr[1][i];
    forn(i, n) {
        smr[i] = gr[0][i];
        if(i) smr[i] += smr[i - 1];
    }
    forn(i, n) {
        smc[i] = gr[1][i];
        if(i) smc[i] += smc[i - 1];
    }

    ll t = 1;
    forn(i, n) if (i) frr[i] = frr[i - 1] + t * gr[0][i], t++;
    t = 1;
    for (int i = n - 2; i >= 0; i--) srl[i] = srl[i + 1] + t * gr[1][i], t++;
    t = 1;
    forn(i, n) if (i) srr[i] = srr[i - 1] + t * gr[1][i], t++;
    t = 1;
    for (int i = n - 2; i >= 0; i--) frl[i] = frl[i + 1] + t * gr[0][i], t++;

    ll ans = 0, curA = 0;
    ll i = 0, j = 0;
    t = 0;
    while (1) {
        ll cur;
        if (i == 0) {
            cur = frr[n - 1];
            cur -= frr[j];
            ll sumrow = smr[n - 1];
            sumrow -= smr[j];
            cur += -j * sumrow + t * sumrow;
            ll sumcol = smc[n - 1];
            if(j) sumcol -= smc[j - 1];
            cur += srl[j] + (t + (n - j)) * sumcol;
            ans = max(ans, curA + cur);
        } else {
            cur = srr[n - 1];
            cur -= srr[j];
            ll sumcol = smc[n - 1];
            sumcol -= smc[j];
            cur += -j * sumcol + t * sumcol;
            ll sumrow = smr[n - 1];
            if(j) sumrow -= smr[j - 1];
            cur += frl[j] + (t + (n - j)) * sumrow;
            ans = max(ans, curA + cur);
            ans = max(ans, curA + cur);
        }

        if(j == n - 1) {
            if(i == 0) curA += (t + 1) * gr[1][j];
            else curA += (t + 1) * gr[0][j];
            break;
        }

        curA += (t + 1) * gr[abs(i - 1)][j] + (t + 2) * gr[abs(i - 1)][j + 1];

        t += 2;

        if(i == 0)
            i += 1, j += 1;
        else j += 1, i -= 1;
    }

    cout << max(ans, curA) << endl;

    return 0;
}