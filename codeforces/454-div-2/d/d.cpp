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
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    vvi ans(155);
    ans[0] = {1};
    ans[1] = {1, 0};
    vi f = ans[0], s = ans[1];
    for(int i = 2; i < 154; i++) {
        ans[i] = s;
        ans[i].push_back(0);
        bool ok = true;
        vi tmp = ans[i];
        for(int i = 0; i < f.size(); i++) {
            tmp[tmp.size() - i - 1] += f[f.size() - i - 1];
            if(abs(tmp[tmp.size() - i - 1]) > 1) ok = false;
        }
        if(!ok) for(int j = 0; j < f.size(); j++)
                ans[i][ans[i].size() - j - 1] -= f[f.size() - j - 1];
        else ans[i] = tmp;
        f = s, s = ans[i];
    }
    for(auto &e: ans) reverse(e.begin(), e.end());

    int n; cin >> n;
    cout << ans[n].size() - 1 << endl;
    for(auto &e: ans[n])
        cout << e << " ";
    cout << endl << ans[n - 1].size() - 1 << endl;
    for(auto &e: ans[n - 1])
        cout << e << " ";



    return 0;
}
