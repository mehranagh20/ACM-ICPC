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

vi nums;
vvi memo;
int n;

int what(int sum) {
    if(sum % 10 < 5) sum -= sum % 10;
    else sum += (10 - (sum % 10));
    return sum;
}

int solve(int i, int d) {
    if(i == n) return 0;
    if(d == 0) {
        int sum = 0;
        for(int j = i; j < n; j++) sum += nums[j];
        sum = what(sum);
        return sum;

    }
    int &ans = memo[i][d];
    if(ans != inf) return ans;
    int sum = 0;
    for(int k = i; k < n; k++) {
        sum += nums[k];
        int x = what(sum);
        ans = min(ans, x + solve(k + 1, d - 1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int d;
    while(cin >> n >> d) {
        nums.assign(n, 0);
        for(auto &e: nums) cin >> e;
        memo.assign(n + 10, vi(d + 10, inf));
        cout << solve(0, d) << endl;
    }

    return 0;
}
