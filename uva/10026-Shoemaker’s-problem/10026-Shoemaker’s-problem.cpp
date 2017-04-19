//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;
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

bool comp(iii a, iii b) {
    if(a.first.first * b.first.second > a.first.second * b.first.first) return true;
    if(a.first.first * b.first.second == a.first.second * b.first.first) return a.second < b.second;
    return false;
}

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        int n; cin >> n;
        viii nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i].first.second >> nums[i].first.first, nums[i].second = i;
        sort(nums.begin(), nums.end(), comp);
        cout << nums[0].second + 1;
        for(int i = 1; i < n; i++) cout << " " << nums[i].second + 1;
        cout << endl;


    }

    return 0;
}
