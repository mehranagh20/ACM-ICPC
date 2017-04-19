//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

void floyd(vvi &adjMat, int m) {
    for(int k = 0; k < m; k++) for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
                adjMat[i][j] += adjMat[i][k] * adjMat[k][j];
}

int main() {
    int m, tc = 0;
    while(cin >> m) {
        int mx = 0;
        vvi adjMat(31, vi(31, 0));
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            mx = max(max(a, b), mx);
            adjMat[a][b] = 1;
        }
        if(m) mx++;
        floyd(adjMat, mx);
        for(int k = 0; k < mx; k++)
            if(adjMat[k][k]) for(int i = 0; i < mx; i++) for(int j = 0; j < mx; j++)
                        if(adjMat[i][k] && adjMat[k][j]) adjMat[i][j] = -1;
        cout << "matrix for city " << tc++ << endl;
        for(int i = 0; i < mx; i++) {
            for(int j = 0; j < mx; j++) {
                if (j) cout << " " << adjMat[i][j];
                else cout << adjMat[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
