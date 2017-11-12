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

vvi items;
vi price;
int nitem;

map<vi, int> memo;
int solve(vi state) {
    bool done = true;
    for(auto &e: state) if(e) done = false;
    if(done) return 0;
    if(memo.find(state) != memo.end()) return memo[state];
    memo[state] = inf;
    int &now = memo[state];
    for(int i = 0; i < nitem; i++) {
        bool pos = true;
        vi tmp = state;
        for(int j = 0; j < items[i].size(); j++) {
            if(items[i][j] > state[j]) {
                pos = false;
                break;
            }
            else tmp[j] -= items[i][j];
        }

        if(pos)
            now = min(now, solve(tmp) + price[i]);

    }
    return now;
}



int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        memo.clear();
        nitem = n;
        items.clear(), price.clear();
        for(int i = 0; i < n; i++) {
            vi tmp(n, 0);
            tmp[i] = 1;
            int p; cin >> p;
            price.push_back(p);
            items.push_back(tmp);
        }
        int m; cin >> m;
        nitem += m;
        for(int i = 0; i < m; i++) {
            vi tmp(n);
            for(auto &e: tmp) cin >> e;
            int p; cin >> p;
            items.push_back(tmp);
            price.push_back(p);
        }

        int o; cin >> o;
        for(int i = 0; i < o; i++) {
            vi cur(n);
            for(auto &e: cur) cin >> e;
            cout << solve(cur) << endl;
        }
    }




    return 0;
}
