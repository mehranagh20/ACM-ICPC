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

vector<llu> memo;

void solve(int n, int back, llu &times) {
    times++;
    if(n <= 1) return;
    if(memo[n]) {
        times += memo[n];
        return;
    }
    llu t = 0;
    for(int i = 1; i <= back; i++) solve(n - i, back, t);
    memo[n] = t;
    times += t;
}


int main() {
    ios::sync_with_stdio(0);
    int n, back, tc = 1;
    while(cin >> n >> back && n < 61) {
        cout << "Case " << tc++ << ": ";
        memo.clear(); memo.resize(n + 10, 0);
        llu time = 0;
        solve(n, back, time);
        cout << time << endl;
    }
    return 0;
}