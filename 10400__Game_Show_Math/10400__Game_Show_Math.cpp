#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const int mx = 32000;

vi nums;
vector<vector<bool>> memo;
int n, target;

bool sol(int id, int tot, vector<char> &ans) {
    vi &nn = nums;
    if(tot >= mx || tot <= -mx) return false;
    if(id == nums.size()) return tot == target;
    int tmp = tot + mx;
    if(memo[id][tmp]) return false;
    if(sol(id + 1, tot + nums[id], ans)) {
        ans[id - 1 ] = '+';
        return true;
    }
    if(sol(id + 1, tot - nums[id], ans)) {
        ans[id - 1] = '-';
        return true;
    }
    if(sol(id + 1, tot * nums[id], ans)) {
        ans[id - 1] = '*';
        return true;
    }
    if(tot % nums[id] == 0 && sol(id + 1, tot / nums[id], ans)) {
        ans[id- 1] = '/';
        return true;
    }
    memo[id][tmp] = true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        vi &nn = nums;
        cin >> n;
        nums.clear(); nums.resize(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        cin >> target;
        memo.clear(); memo.resize(n + 1, vector<bool>(mx * 2 + 10, false));
        vector<char> ans(n + 1);
        if(sol(1, nums[0], ans)) {
           for(int i = 0; i < n - 1; i++) cout << nums[i] << ans[i];
            cout << nums[n - 1] << "=" << target << endl;
        }
        else cout << "NO EXPRESSION\n";
    }
    return 0;
}