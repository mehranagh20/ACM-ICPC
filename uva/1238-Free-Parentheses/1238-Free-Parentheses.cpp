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

vi sig, vals;
int n;
vvvi memo;
vector<bool> all;

void solve(int id, int val, int right) {
    if(id == n) {
        all[val + 3000] = true;
        return;
    }
    if(memo[id][val + 3000][right]) return;
    memo[id][val + 3000][right] = 1;
    int cur_val = val + vals[id] * sig[id] * (right % 2 ? -1 : 1);
    if(right) solve(id + 1, cur_val, right - 1);
    if(sig[id] < 0) solve(id + 1, cur_val, right + 1);
    solve(id + 1, cur_val, right);
}

int main() {
    ios::sync_with_stdio(0);
    string line;
    while(getline(cin, line) && cin) {
        stringstream ss(line);
        sig.clear(), vals.clear();
        int tmp; ss >> tmp;
        char c;
        sig.push_back(1), vals.push_back(tmp);
        while(ss >> c >> tmp) vals.push_back(tmp), sig.push_back((c == '-' ? -1 : 1));
        n = vals.size();
        all.assign(6000, 0);
        memo.assign(n + 1, vvi(6000, vi(n + 1, 0)));
        solve(0, 0, 0);
        int ans = 0;
        for(int i = 0; i <= 6000; i++) ans += all[i];
        cout << ans << endl;
    }

    return 0;
}
