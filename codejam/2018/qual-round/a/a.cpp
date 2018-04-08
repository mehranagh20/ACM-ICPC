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

ll getP(string str) {
    ll p = 1, ans = 0;
    for(auto &e: str)
        if(e == 'S') ans += p;
        else p *= 2;
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        ll d; cin >> d;
        string str, s2; cin >> str, s2 = str;
        sort(s2.begin(), s2.end()), reverse(s2.begin(), s2.end());
        if(getP(s2) > d) cout << "IMPOSSIBLE" << endl;
        else {
            ll mn = 0;
            while(1) {
                if(getP(str) <= d) break;
                for(int i = str.size() - 1; i >= 1; i--)
                    if(str[i] == 'S' && str[i - 1] == 'C') {
                        swap(str[i], str[i - 1]), mn++;
                        break;
                    }
            }
            cout << mn << endl;
        }

    }


    return 0;
}