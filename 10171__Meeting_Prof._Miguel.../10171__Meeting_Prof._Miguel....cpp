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

void floyd(vvi &adjMat) {
    for(int k = 0; k < adjMat.size(); k++) for(int i = 0; i < adjMat.size(); i++) for(int j = 0; j < adjMat.size(); j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int n;
    while(cin >> n && n) {
        vvi adultG(27, vi(27, inf)), youngG(27, vi(27, inf));
        for(int i = 0; i < 27; i++) adultG[i][i] = youngG[i][i] = 0;
        for(int i = 0; i < n; i++) {
            char a, b, c, d;
            int cost; cin >> a >> b >> c >> d >> cost;
            if(c == d) continue;
            if(a == 'Y') {
                youngG[c - 65][d - 65] = cost;
                if(b == 'B') youngG[d - 65][c - 65] = cost;
            }
            else {
                adultG[c - 65][d - 65] = cost;
                if(b == 'B')
                    adultG[d - 65][c - 65] = cost;
            }
        }
        char a, b; cin >> a >> b;
        int f = a - 65, s = b - 65;
        floyd(adultG); floyd(youngG);
        int ans = inf;
        for(int i = 0; i < 27; i++) ans = min(ans, adultG[s][i] + youngG[f][i]);
        if(ans == inf) cout << "You will never meet.\n";
        else {
            cout << ans;
            for (int i = 0; i < 27; i++)
                if (adultG[s][i] + youngG[f][i] == ans) cout << " " << char(i + 65);
            cout << endl;
        }
    }


    return 0;
}
