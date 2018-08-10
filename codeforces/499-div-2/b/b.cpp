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

vi fs;
int n, k;

bool possible(int d) {
    int i = 0, p = 0;
    while(i < k) {
        int num = 0, type = fs[i];
        for(int j = i; j < k; j++) {
            if(fs[j] != type)
                break;
            i++, num++;
        }
        num /= d;
        p += num;
    }

    return p >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    fs.assign(k, 0);
    forn(i, k) cin >> fs[i];
    sort(fs.begin(), fs.end());

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        if(possible(i)) ans = i;
    }
    cout << ans << endl;



    return 0;
}