//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<short int> vi;
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

vvi memo;
vi f;
short int solve(int w, int h, int bm) {
    short int &res = memo[w][bm];
    if(res != -1) return res;

    int sum = 0, r = -1, n = 0;
    for(int i = 0; i < f.size(); i++) if(bm & (1 << i))
            n++, sum += f[i], r = i;
    // int h = sum / w;
    if((n == 0 && w * h == 0) || (n == 1 && f[r] == w * h)) return 1;

    int i = bm;
    while(i) {
        i = (i - 1) & bm;
        int s = 0;
        for(int j = 0; j < f.size(); j++) s += (i & (1 << j) ? f[j] : 0);
        if(!s) continue;

        if(s % h == 0 && h * (s / h) == s && h * (w - s / h) == sum - s) {
            res = solve(h, s / h, i) && solve(h, w - s / h, (~i & bm));
            if(res) return 1;
        }

        if(s % w == 0 && w * (s / w) == s && w * (h - s / w) == sum - s) {
            res = solve(w, s / w, i) && solve(w, h - s / w, (~i & bm));
            if(res) return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    int w, h, n, tc = 1;
    while(cin >> n >> w >> h) {
        f.assign(n, 0);
        int sum = 0;
        for(auto &e: f) {
            cin >> e;
            sum += e;
        }
        if(sum != w * h) cout << "Case " << tc++ << ": " << "No" << endl;
        else {
            memo.assign(max(w, h) + 10, vi(1 << n + 1, -1));
            cout << "Case " << tc++ << ": " << (solve(w, h, (1 << n) - 1) ? "Yes" : "No") << endl;
        }
    }



    return 0;
}
