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

vector<pair<ll, ll>> sorted;
vector<ll> memo;
int k;
ll solve(int i) {
    if(i == k) return 0;
    if(i > k)
        return -inf;
    ll &ans = memo[i];
    if(ans != -1) return ans;
    ans = 0;
    ans = max(ans, solve(i + 1));
    int l = 0, h = k - 1;
    int s = sorted[i].second;
    int an = -1;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(sorted[mid].first <= s) l = mid + 1;
        else {
            an = mid;
            h = mid - 1;
        }
    }
    if(an == -1) {
        ans = max(ans, sorted[i].second - sorted[i].first + 1);
        return ans;
    }
    ans = max(ans, solve(an) + sorted[i].second - sorted[i].first + 1);
    return ans;

}


int main() {
    ios::sync_with_stdio(0);
    ll n; cin >> n >> k;
    sorted.assign(k, pair<ll, ll>());
    for(auto &e: sorted) cin >> e.first >> e.second;
    sort(sorted.begin(), sorted.end());
    memo.assign(k + 10, -1);
    cout << n - solve(0) << endl;

    return 0;
}
