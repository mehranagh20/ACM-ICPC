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

int n;
vi coinValue, memo;

int change(int value) {
    if (value == 0) return 0;
    if (value < 0) return inf;
    if (memo[value] < inf) return memo[value];
    for (int i = 0; i < n; i++)
        memo[value] = min(memo[value], change(value - coinValue[i]));
    return memo[value] += 1;
}


int main() {
    ios::sync_with_stdio(0);
    coinValue.resize(100);
    n = 100;
    for(int i = 1; i <= 100; i++) coinValue[i - 1] = i * i;
    memo.resize(10001, inf);
    int tc, q; cin >> tc;
    while(tc--) {
        cin >> q;
        cout << change(q) << endl;
    }

    return 0;
}