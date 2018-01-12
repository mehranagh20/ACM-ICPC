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

map<vi, bool> memo1;
map<vi, ull> memo2;
vvi real_nums;
int n;
void numbers(int x, vi vec) {
    sort(vec.begin(), vec.end());
    if(memo1.find(vec) != memo1.end()) return;
    if(x == 0 && vec.size() <= n) {
        memo1[vec] = true;
        real_nums.push_back(vec);
        while(real_nums.back().size() < n) real_nums.back().push_back(0);
        return;
    }
    if(vec.size() > n) return;
    memo1[vec] = true;
    for(int i = 1; i <= x; i++) {
        vec.push_back(i);
        numbers(x - i, vec);
        vec.pop_back();
    }
}

ull solve(vi vec) {
    sort(vec.begin(), vec.end());
    if(vec[0] < 0) return 0;
    if(vec[vec.size() - 2] == 0) return 1;
    if(memo2.find(vec) != memo2.end()) return memo2[vec];
    ull &ans = memo2[vec];
    ans = 0;
    vi tmp = vec;
    for(int i = 0; i < vec.size(); i++) {
        tmp[i]--;
        ans += solve(tmp);
        tmp[i]++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int m; cin >> n >> m;
    vi tmp;
    numbers(m - 1, tmp);
    set<ull> all;
    for(auto &e: real_nums) all.insert(solve(e));
    for(auto &e: all) cout << e << endl;

    return 0;
}
