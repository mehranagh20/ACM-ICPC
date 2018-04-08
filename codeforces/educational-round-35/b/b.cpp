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
#define F first
#define S second
#define pb push_back

bool pos(int a, int b, int n, int x) {
    if(a < x || b < x) return false;
    return (a / x + b / x >= n);
}

int main() {
    ios::sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    int l = 1, h = 1000000;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(mid == 0) mid = 1;
        if(pos(a, b, n, mid)) l = mid + 1;
        else h = mid - 1;
    }
    cout << l - 1 << endl;


    return 0;
}
