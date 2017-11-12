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

vvi graph;
vvii memo;

ii solve(int id, int used) {
    ii &now = memo[id][used];
    if(now != ii(-1, -1)) return now;
    now = ii(0, 0);
    if(used) {
        for(auto &nei: graph[id]) {
            ii cur = solve(nei, 0);
            now.second |= cur.second;
            now.first += cur.first;
        }
        return now;
    }
    else {
        ii if_use = ii(1, 0), if_not_use = ii(0, 0);
        for(auto &nei: graph[id]) {
            ii cur = solve(nei, 1);
            if_use.first += cur.first;
            if_use.second |= cur.second;

            cur = solve(nei, 0);
            if_not_use.first += cur.first;
            if_not_use.second |= cur.second;
        }
        if(if_use.first == if_not_use.first) {
            now = if_not_use;
            now.second = 1;
        }
        else if(if_use.first > if_not_use.first) now = if_use;
        else now = if_not_use;
        return now;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int ind = 0;
        map<string, int> mp;

        graph.assign(n, vi());
        string str, str2; cin >> str; mp[str] = ind++;
        for(int i = 1; i < n; i++) {
            cin >> str >> str2;
            if(mp.find(str) == mp.end()) mp[str] = ind++;
            if(mp.find(str2) == mp.end()) mp[str2] = ind++;
            graph[mp[str2]].push_back(mp[str]);
        }
        memo.assign(n + 10, vii(3, ii(-1, -1)));
        ii ans = solve(0, 0);
        cout << ans.first << " " << (ans.second ? "No" : "Yes") << endl;
    }


    return 0;
}
