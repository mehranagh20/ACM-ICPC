//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

int main() {
   int n, m, tc = 1;
    while(cin >> n && n) {
        map<string, int> mp;
        int ind = 0;
        for(int i = 0; i < n; i++) {
            string tmp; cin >> tmp;
            mp[tmp] = ind++;
        }
        vector<vector<double>> adjMat(n, vector<double>(n, 0));
        cin >> m;
        for(int i = 0; i < m; i++) {
            double tmp;
            string a, b; cin >> a >> tmp >> b;
            adjMat[mp[a]][mp[b]] = tmp;
        }
        for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
                    adjMat[i][j] = max(adjMat[i][j], adjMat[i][k] * adjMat[k][j]);
        bool pos = false;
        for(int i = 0; i < n; i++) if(adjMat[i][i] > 1.) pos = true;
        cout << "Case " << tc++ << ": ";
        if(pos) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}
