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
    int n, k; cin >> n >> k;
    string str; cin >> str;
    sort(str.begin(), str.end());
    int ans = 0, num = 0;
    char last;
    forn(i, n) {
        if(num == k) break;
        if(i == 0) {
            ans += str[i] - 'a' + 1, num++;
            last = str[i];
            continue;
        }
        if(str[i] - last >= 2) {
            ans += str[i] - 'a' + 1, num++;
            last = str[i];
        }

    }
    if(num < k) ans = -1;
    cout << ans << endl;


    return 0;
}