#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9
vi fib;
vector<pair<double, int>> memo;
int n;
double tot;

double sol(int val, int sum) {
    if(val < 0) return inf;
    if(val == 0)
        return 0;
    if(memo[val].first != -1)
        return memo[val].first;
    double ans = inf;
    for(int i = 2; i < fib.size(); i++)
        ans = min(ans, sol(val - fib[i], sum + fib[i + 1]) + abs(fib[i + 1] - fib[i] * 1.6));
    memo[val].first = ans; memo[val].second = sum;
    return memo[val].first;
}

int main() {
    ios::sync_with_stdio(0);
    fib.push_back(0);
    fib.push_back(1);
    while(true) {
        if(fib.back() <= 1000) fib.push_back(fib.back() + fib[fib.size() - 2]);
        else break;
    }
    memo.resize(1010, make_pair(-1, inf));
    while(cin >> n && n) {
        tot = n * 1.6;
        cout << fixed << setprecision(2) << sol(n, 0) << endl;
    }
    return 0;
}