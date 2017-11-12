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
    int n; cin >> n;
    vvi mat(n + 1, vi(n + 1, 0)); // holds the matrix given by input.
    vi row(n + 1, 0), col(n + 1, 0); // counts how many ones are in each row and column.
    for(int i = 0; i < n - 1; i++) { // take input.
        int a, b; cin >> a >> b;
        mat[a][b] = 1;
        col[b]++, row[a]++;
    }

    viii ans; // holds the steps to make the matrix special.
    for(int j = n; j >= 1; j--) { // in each step we make sure in column j we have no one above main diagonal.
        for(int k = 1; k < j; k++) // we find an empty(no ones in it) column and replace it by j'th column.
            if(!col[k]) {
                ans.push_back(iii(2, ii(k , j)));
                for(int i = 1; i <= n; i++) swap(mat[i][k], mat[i][j]); // swaping columns
                swap(col[k], col[j]);
                break;
            }

        for(int k = 1; k < j; k++) // we made sure that in j'th column there is no one above diagonal, so now we can fix the j'th row.
            // we find a row with ones in it and replace it with j'th row. this works because there is only n - 1 ones
            if(row[k]) {
                ans.push_back(iii(1, ii(k , j)));
                swap(mat[j], mat[k]);
                swap(row[k], row[j]); // swaping rows.
                break;
            }
        for(int i = 1; i <= n; i++) col[i] -= mat[j][i]; // we fixed j'th row, so we must not consider its ones again, we remove ones in this fixed row.
    }

    cout << ans.size() << endl;
    for(auto &e: ans) cout << e.first << " " << e.second.first << " " << e.second.second << endl;
    return 0;
}
