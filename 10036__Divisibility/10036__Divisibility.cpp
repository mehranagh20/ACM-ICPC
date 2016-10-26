#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vvi memo;
vi nums;
int k;

int solve(int id, int currSum) {
    vvi &m = memo;
    if(id == nums.size())
        return (currSum % k) == 0 ? 1 : 0;
    int tmp = currSum % k;
    if(tmp < 0) tmp += k; tmp %= k;
    if(memo[id][tmp] != inf) return memo[id][tmp];
    if(solve(id + 1, currSum + -nums[id]) || solve(id + 1, currSum + nums[id])) return memo[id][tmp] = 1;
    return memo[id][tmp] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n >> k;
        nums.resize(n); memo.clear();
        memo.resize(n + 1, vi(k + 1, inf));
        for(int i = 0; i < n; i++) cin >> nums[i];
        vvi &tmp = memo;
        if(solve(1, nums[0])) cout << "Divisible\n";
        else cout << "Not divisible\n";

    }
    return 0;
}