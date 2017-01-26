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

void floyd(vvd &adjMat, int m) {
    for(int k = 0; k < m; k++) for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int n, m;
    while(cin >> n >> m && (n || m)) {
        vvd edjMat(n, vd(n, inf));
        for(int i = 0; i < n; i++) edjMat[i][i] = 0;
        vii coor(n);
        for(int i = 0; i < n; i++) {
            cin >> coor[i].first >> coor[i].second;
            coor[i].first--; coor[i].second--;
        }
        vvi dPaths(n, vi(n));
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--; b--;
            dPaths[a][b] = dPaths[b][a] = 1;
            edjMat[a][b] = edjMat[b][a] = sqrt(pow(coor[a].first - coor[b].first, 2) + pow(coor[a].second - coor[b].second, 2));
        }
        floyd(edjMat, n);
        ii ans;
        double tot = -inf, shortest = inf;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
                if(!dPaths[i][j]) {
                    double dif = 0, dis = sqrt(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2));
                    for(int k = 0; k < n; k++) for(int d = 0; d < n; d++)
                            if(edjMat[k][i] + dis + edjMat[j][d] < edjMat[k][d])
                                dif += edjMat[k][d] - (edjMat[k][i] + dis + edjMat[j][d]);
                    if(dif >= 1 && (dif > tot || (dif == tot && shortest > dis))) {
                        shortest = dis; tot = dif;
                        ans.first = i; ans.second = j;
                    }
                }
            }
        if(tot == -inf) cout << "No road required\n";
        else
            cout << ans.first + 1 << " " << ans.second + 1 << endl;
    }

    return 0;
}
