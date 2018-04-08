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

vvi c_col(vvi &g) {
    vvi cur = g;
    for(int i = 0; i < 7; i++) {
        int sz = g[i].size();
        for(int j = 0; j < g[i].size(); j++) if(g[i][j] == sz) cur[i][j] = 0;
    }
    return cur;
}

vvi c_row(vvi &g) {
    vvi cur = g;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int num = 1;
            int k = i - 1;
            while(k >= 0 && g[k].size() >= j + 1) {
                num++; k--;
            }
            k = i + 1;
            while(k < 7 && g[k].size() >= j + 1) {
                num++; k++;
            }
            if(num == g[i][j]) cur[i][j] = 0;
        }
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        bool get = true;
        bool game = false;
        vvi g(7);
        while(1) {

            if(get) {
                get = false;
                int i, j; cin >> i >> j;
                n--;
                g[j - 1].push_back(i);
                if(g[j - 1].size() > 7) {
                    game = true;
                    while(n--) cin >> i >> j;
                    break;
                }
            }
            else {
                vvi tmp1 = c_col(g);
                vvi tmp2 = c_row(g);
                if(tmp1 == g && tmp2 == g) {
                    if(!n) break;
                    get = true;
                }


                else {
                    vvi tmp3 (7, vi());
                    for(int i = 0; i < 7; i++) for(int j = 0; j < g[i].size(); j++) if(tmp1[i][j] && tmp2[i][j])
                                tmp3[i].push_back(g[i][j]);
                    g = tmp3;
                }
            }
        }
        if(game) cout << "Game Over!" << endl;
        else {
            for (int i = 6; i >= 0; i--) {
                for (int j = 0; j < 7; j++) {
                    if (g[j].size() >= i + 1) cout << g[j][i];
                    else cout << "#";
                }
                cout << endl;
            }
        }
        cout << endl;

    }



    return 0;
}
