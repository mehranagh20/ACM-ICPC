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
typedef vector<vs> vvs;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    cin.get();
    vector<set<string>> valid(m);
    for(int i = 0; i < m; i++) {
        string l; getline(cin, l);
        stringstream ss(l);
        while(ss >> l) valid[i].insert(l);
    }
    vi score(n, 0);
    for(int i = 0; i < k; i++) {
        vvs game(m, vs(n));
        char start; cin >> start;
        for(int j = 0; j < n; j++) for(int r = 0; r < m; r++)
            cin >> game[r][j];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(game[i][j] == "EMPTY") continue;
                if(valid[i].find(game[i][j]) == valid[i].end()) continue;
                if(game[i][j][0] != start) continue;
                bool same = false;
                for(int r = 0; r < n; r++) if(r != j && game[i][r] == game[i][j])
                        same = true;
                score[j] += same ? 5 : 10;
            }
        }
    }
    cout << score[0];
    for(int i = 1; i < n; i++) cout << " " << score[i];
    cout << endl;


    return 0;
}
