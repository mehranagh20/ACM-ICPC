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
    int w, h;
    while(cin >> h >> w && (w || h)) {
        vs grid(h);
        for(auto &e: grid) cin >> e;
        int ans = 0;
        for(int i = 0; i < h; i++) {
            int j = 0;
            while(j < w){
                int now = 0;
                char tmp = grid[i][j];
                int l = tmp - '0';
                now += l;
                vs cur = grid;
                for(int k = j; k < j + l; k++) cur[i][k] = '0';
                for(int ii = i - 1; ii >= 0; ii--) {
                    int jj = 0;
                    while(jj < w) {
                        int ll = cur[ii][jj] - '0';
                        bool ok = true;
                        if(ii + 1 < h) {
                            int d = ii + 1;
                            for(int k = jj; k < jj + ll; k++) if(cur[d][k] != '0') {
                                    ok = false;
                                    break;
                                }
                        }
                        if(ok) {
                            for(int k = jj; k < jj + ll; k++) cur[ii][k] = '0';
                            now += ll;
                        }

                        if(cur[ii][jj] == '0')
                            ll = 1;
                        jj += ll;
                    }
                }

                ans = max(ans, now);
                if(tmp == '0') l = 1;
                j += l;
            }
        }
        cout << ans << endl;

    }


    return 0;
}
