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

void floyd(vector<vvd> &adjMat, vvvi &path) {
    for(int s = 1; s < adjMat.size(); s++) for(int k = 0; k < adjMat.size(); k++)
            for(int i = 0; i < adjMat.size(); i++) for(int j = 0; j < adjMat.size(); j++) {
                    double tmp = adjMat[i][k][s - 1] * adjMat[k][j][0];
                    if(tmp > adjMat[i][j][s]) {
                        adjMat[i][j][s] = tmp;
                        path[i][j][s] = k;
                    }
                }
}

int main() {
    int n;
    while(cin >> n) {
        vector<vvd> adjMat(n, vvd(n, vd(n, 0)));
        vvvi path(n, vvi(n, vi(n, 0)));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
                path[i][j][0] = i;
                if(i == j) {
                    adjMat[i][i][0] = 1;
                    continue;
                }
                cin >> adjMat[i][j][0];
            }
        floyd(adjMat, path);
        int ans = -1, s;
        for(int i = 1; i < n; i++) {  for (int j = 0; j < n; j++) {
                if (adjMat[j][j][i] > 1.01) {
                    s = i;
                    ans = j;
                    break;
                }
            }
            if(ans != -1) break;
        }
        if(ans == -1) cout << "no arbitrage sequence exists\n";
        else {
            vi an; an.push_back(ans);
            int tmp = ans;
            for(int i = s; i >= 0; i--) {
                tmp = path[ans][tmp][i];
                an.push_back(tmp);
            }
            cout << an.back() + 1;
            for(int i = s; i >= 0; i--) cout << ' ' << an[i] + 1 ;
            cout << endl;
        }
    }

    return 0;
}
