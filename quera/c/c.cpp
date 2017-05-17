//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n , m; cin >> n >> m;
    vvi mo(n, vi(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mo[i][j];
    int q; cin >> q;
    vector<ull> row(n + 10, 1), col(m + 10, 1);
    for(int i = 0; i < q; i++) {
        char t; int r, l, k;
        cin >> t >> l >> r >> k;
        r--; l--;
        if(t == 'C')
            for(int i = l; i <= r; i++) {
                col[i] *= k;
                if(col[i] > 1000000000) col[i] = 0;
            }
        else {
            for(int i = l; i <= r; i++) {
                row[i] *= k;
                if(row[i] > 1000000000) row[i] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        ll amount = col[j] * row[i];
        if(amount == 0) mo[i][j] = 0;
        else mo[i][j] /= amount;
    }

    for(int i = 0; i < n; i++) {
        cout << mo[i][0];
        for(int j = 1; j < m; j++) cout << " " << mo[i][j];
        cout << endl;
    }


    return 0;
}
