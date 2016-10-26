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
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vi dis;
int n, k;
vvi memo;

int sol(int rem, int pos) {
    if(rem == 0) return dis.back() - dis[pos];
    if(memo[rem][pos] != -1) return memo[rem][pos];
    int ans = inf;
    for(int i = pos + 1; i < n + 1; i++) {
        int tmp = max(sol(rem - 1, i), dis[i] - dis[pos]);
        ans = min(ans, tmp);
    }
    return memo[rem][pos] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n >> k) {
        dis.clear(); dis.resize(n + 2);
        memo.clear(); memo.resize(k + 1, vi(n + 1, -1));
        dis[0] = 0;
        int tmp = 0;
        for(int i = 1; i < n + 2; i++) {
            cin >> tmp;
            dis[i] = dis[i - 1] + tmp;
        }
        cout << sol(k, 0) << endl;
    }

    return 0;
}