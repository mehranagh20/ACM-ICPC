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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int y, m, d; cin >> y >> m >> d;
        int n; cin >> n;
        vvi graph(26);
        vvi same(26, vi(26, 1));
        for(int i = 0; i < n; i++) {
            char a, b; cin >> a >> b;
            if(same[a - 'A'][b - 'A'] && a != b) {
                graph[a - 'A'].push_back(b - 'A');
                graph[b - 'A'].push_back(a - 'A');
                same[a - 'A'][b - 'A'] = same[b - 'A'][a - 'A'] = 0;
            }
        }
        int f;
        if(y < 470 && m == 2) f = 12;
        else {
            if(m == 2) {
                if(d < 14) f = 0;
                else f = 12;
            }
            else {
                f = (14 - m) % 12;
            }
        }
        if(y < 470) f += (470 - y - 1) * 12;
        //cout << f << endl;
        //cout << need;
        vector<vd> d1(f + 2, vd(26, 0)), d2(f + 2, vd(26, 0));
        char a, b; cin >> a >> b;
        d1[0][a - 'A'] = d2[0][b - 'A'] = 1;
        for(int i = 0; i < f + 1; i++) {
            for(int j = 0; j < 26; j++) {
                for(auto &e : graph[j]) {
                    d1[i + 1][e] += d1[i][j] / (graph[j].size() + 1);
                    d2[i + 1][e] += d2[i][j] / (graph[j].size() + 1);
                }
                d2[i + 1][j] += d2[i][j] / (graph[j].size() + 1);
                d1[i + 1][j] += d1[i][j] / (graph[j].size() + 1);
            }
        }
        double ans = 0;
        //cout << f << endl;
        for(int i = 0; i < 26; i++) ans += d1[f][i] * d2[f][i];
        cout << fixed << setprecision(5) << ans << endl;
    }


    return 0;
}
