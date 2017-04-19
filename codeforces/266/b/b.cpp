//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ull> vi;
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

#define inf 1000000000
#define eps 1e-9

// author: Mehran

// solution:
// You can not use n ^ 2 algorithm since the input is 10 ^ 5
// 1. if totalSum % 3 is not 0 then there is no answer
// 2. we traverse the numbers backwardly and for all i of for see how many times our (comulativeSum / 3) has become (totalSum / 3) till now and store it in ways array.
// 3. now we traverse the numbers again left to right, every where that our comulativeSum / 3 has become (totalSum / 3) we add answer by ways[i + 2]
// 4. why ? since our sum till now is totalSum / 3 and we know that in ways[i + 2] is number of times that from end our sum has became totalSum / 3
// 5. then the middle of array must be totalSum / 3 too
// so it was solvable in O(n)

int main() {
    ios::sync_with_stdio(0);
    ll n;
    while(cin >> n) {
        ll sum = 0, cur = 0;
        ull ans = 0;
        vi nums(n), ways(n, 0);
        for(auto &e : nums) cin >> e, sum += e;
        if(sum % 3 == 0) { // 1
            int w = 0;
            for(int i = nums.size() - 1; i >= 0; i--) { // 2
                cur += nums[i];
                if(cur == sum / 3) w++;
                ways[i] = w;
            }
            cur = 0;
            for(int i = 0; i <= n - 3; i++) { // 3
                cur += nums[i];
                if(cur == sum / 3) ans += ways[i + 2];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
