//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, x, t, k;
vi W, V;
vvvi memo;

int value(int id, int w, int gotTillNow, int taken) {
    if (id == (2 * k) || w == 0 || taken == 2 * (n + 1)) return 0;
    if (memo[id][w][taken] != -1) return memo[id][w][taken];
    //int tmp = floor(.1 * (t + gotTillNow + W[id]));
    if (W[id] > w ) return memo[id][w][taken] = value(id + 1, w, gotTillNow, taken);//edited
    return memo[id][w][taken] = max(value(id + 1, w, gotTillNow, taken), V[id] + value(id + 1, w - W[id], gotTillNow + W[id], taken + 1));
}

int main() {
    while(cin >> n >> x >> t >> k && (n || x || t || k)) {
        memo.clear(); memo.resize(k * 2 + 1, vvi(x * (n + 1) + 10, vi(2 * (n + 2), -1)));
        W.clear(); V.clear();
        for(int i = 0; i < k; i++) {
            int tmp = 0;
            cin >> tmp;
            W.push_back(tmp); W.push_back(tmp);
            int tmp1 = 0;
            for(int j = 0; j <= n; j++) {
                cin >> tmp; tmp1 += tmp;
            }
            V.push_back(tmp1); V.push_back(tmp1);
        }
        vi &ww = W, &vv = V;
        int maxmoney = floor(double(x * (n + 1)) / 1.1 + 1e-6) - (n + 1) * t; // i do not fucking know why !!!!!!!!! WTF, the question explanation sucks ...
        cout << fixed << setprecision(2) << (double)value(0, maxmoney, 0, 0) / (n + 1) << endl;
    }

    return 0;
}