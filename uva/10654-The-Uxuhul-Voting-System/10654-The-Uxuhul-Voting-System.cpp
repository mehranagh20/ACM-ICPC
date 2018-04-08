//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
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
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

#define mx 8


int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vvi des(n, vi(mx)), real(n, vi(mx));
        for(int i = 0; i < n; i++) for(int j = 0; j < 8; j++) cin >> des[i][j];
        for(int i = 0; i < mx; i++) {
            int tmp = i ^ 1;
            for (int j = 1; j < 3; j++)
                if(des.back()[i ^ (1 << j)] < des.back()[tmp]) tmp = i ^ (1 << j);
            real.back()[i] = tmp;
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < mx; j++) {
                int tmp = j ^ 1, tmp2 = real[i + 1][j ^ 1];
                for(int d = 1; d < 3; d++) if(des[i][real[i + 1][tmp]] > des[i][real[i + 1][j ^ (1 << d)]])
                        tmp = j ^ (1 << d), tmp2 = real[i + 1][j ^ (1 << d)];
                real[i][j] = tmp2;
            }
        }
        int ans = real[0][0];
        for(int i = 2; i >= 0; i--) {
            if(ans & (1 << i)) cout << "Y";
            else cout << "N";
        }
        cout << endl;

    }

    return 0;
}