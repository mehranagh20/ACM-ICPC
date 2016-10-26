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
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int n, r, tc = 1;
    while(cin >> n >> r && (n || r)) {
        int ind = 0;
        map<string, int> mp;
        vvi adjMat(n, vi(n, inf));
        for(int i = 0; i < r; i++) {
            string a, b; cin >> a >> b;
            if(mp.find(a) == mp.end()) mp[a] = ind++;
            if(mp.find(b) == mp.end()) mp[b] = ind++;
            int aa = mp[a], bb = mp[b];
            adjMat[aa][bb] = adjMat[bb][aa] = 1;
        }
        floyd(adjMat, n);
        bool poss = true;
        int mx = -inf;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(adjMat[i][j] == inf) {
                    poss = false;
                    break;
                }
                mx = max(mx, adjMat[i][j]);
            }
            if(!poss) break;
        }
        cout << "Network " << tc++ << ": ";
        if(poss) cout << mx << endl;
        else cout << "DISCONNECTED\n";
        cout << endl;
    }

    return 0;
}
