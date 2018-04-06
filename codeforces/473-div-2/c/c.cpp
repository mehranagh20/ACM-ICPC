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
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

void printS(int n) {
    for(int i = 2; i <= n; i++) cout << 1 << " " << i << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    if(n <= 5) {
        cout << -1 << endl;
        printS(n);
    } else {
        cout << "1 2" << endl << "1 3" << endl << "1 4" << endl;
        for(int i = 5; i <= n; i++) cout << 2 << " " << i << endl;
        printS(n);
    }



    return 0;
}