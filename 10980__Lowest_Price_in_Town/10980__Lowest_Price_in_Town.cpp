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

#define inf 1000000000
#define eps 1e-9

vi memo;
vii prices;
int k;

int solve(int tillNow) {
    if(tillNow <= 0) return 0;
    if(memo[tillNow] != -1) return memo[tillNow];
    int ans = inf;
    for(auto &e : prices)
        ans = min(ans, solve(tillNow - e.first) + e.second);
    return memo[tillNow] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    double d;
    int m, tc = 1;
    while( cin >> d >> m) {
        cout << "Case " << tc++ << ":" << endl;
        memo.clear(); memo.resize(105, -1);
        prices.clear(); prices.resize(m + 1);
        prices[0].first = 1; prices[0].second = (d + eps) * 100;
        for(int i = 1; i <= m; i++) {
            int tmp; cin >> tmp >> d;
            prices[i].first = tmp; prices[i].second = (d + eps) * 100;
        }
        string str;
        cin.get();
        getline(cin, str);
        stringstream ss(str);
        int tmp;
        while(ss >> tmp) {
            cout << "Buy " << tmp << " for $" << fixed << setprecision(2) << (double)solve(tmp) / 100 << endl;
        }
    }

    return 0;
}