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
    int m, n, t; cin >> m >> n;
    int mid = (m / 2);
    if(m == 1) mid = 1;
    vi beh(n);
    forn(i, n) {
        cout << mid << endl;
        fflush(stdout);
        cin >> beh[i];
        if(beh[i] == 0)
            exit(0);
    }
    int truth;
    if(beh[0] == -1) {
        cout << 1 << endl;
        fflush(stdout);
        cin >> t;
        if(t == 0)
            exit(0);
        truth = -1;
        if(t == -1) truth = 1;
    } else {
        cout << m << endl;
        fflush(stdout);
        cin >> t;
        if(t == 0)
            exit(0);
        truth = 1;
        if(t == 1) truth = -1;
    }
    int l = 1, h = m;

    if(truth == 1) l = mid + 1;
    else h = mid - 1;

    int i = 0;
    while(1) {
        i = (i + 1) % n;

        mid = (l + h) / 2;
        cout << mid << endl;
        fflush(stdout);
        cin >> t;
        if(t == 0)
            exit(0);

        if(beh[i] != truth) {
            if(t == -1) t = 1;
            else t = -1;
        }

        if(t == 1) l = mid + 1;
        else h = mid - 1;
    }

    return 0;
}