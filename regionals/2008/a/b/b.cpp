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

int main() {
    ios::sync_with_stdio(0);
    int m, n;
    while(cin >> m >> n && (m || n)) {
        set<int> s;
        vvi grid(m, vi(n));
        for(auto &e: grid) for(auto &ee: e) {
                cin >> ee;
                s.insert(ee);
            }
        map<int, ii> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) if(k != j && grid[i][k] == grid[i][j]) {
                        mp[grid[i][k]] = ii(0, i);
                    }
                for(int k = 0; k < m; k++) if(k != i && grid[i][j] == grid[k][j]) {
                        mp[grid[i][j]] = ii(1, j);
                    }
            }
        }
        for(auto &e: s) {
            if (mp.find(e) == mp.end()) {
                int k, d;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == e) k = i, d = j;
                    }
                }
                bool seted = false;
                for (int i = 0; i < m; i++) {
                    int dd = grid[i][d];
                    if (mp.find(dd) != mp.end() && mp[dd].first == 1) {
                        mp[e] = ii(0, k);
                        seted = true;
                        break;
                    }
                }
                if (!seted) {
                    for (int i = 0; i < n; i++) {
                        int dd = grid[k][i];
                        if (mp.find(dd) != mp.end() && mp[dd].first == 0) {
                            mp[e] = ii(1, d);
                            break;
                        }
                    }
                }
            }
        }
        vi tmp(s.size());
        int i = s.size() - 1;
        for(auto &e: s) {
            tmp[i] = e;
            i--;
        }
        vi ans;
        while(true) {
            bool found = false;
            for(auto &e: tmp) {
                if (e != -1) {
                    if (mp.find(e) != mp.end()) {
                        ii now = mp[e];
                        if (now.first) {
                            int j = now.second;
                            bool ok = true;
                            for (int i = 0; i < m; i++)
                                if (grid[i][j] != e && grid[i][j] != '#')
                                    ok = false;
                            if (ok) {
                                found = true;
                                for(int i = 0; i < m; i++) if(grid[i][j] == e) {
                                        ans.push_back(e);
                                        break;
                                    }
                                for (int i = 0; i < m; i++) {
                                    e = -1;
                                    grid[i][j] = '#';
                                }
                                break;
                            }
                        }
                        else {
                            int i = now.second;
                            bool ok = true;
                            for (int j = 0; j < n; j++)
                                if (grid[i][j] != e && grid[i][j] != '#')
                                    ok = false;
                            if (ok) {
                                found = true;
                                for(int j = 0; j < n; j++) if(grid[i][j] == e) {
                                        ans.push_back(e);
                                        break;
                                    }
                                for (int j = 0; j < n; j++) {
                                    e = -1;
                                    grid[i][j] = '#';
                                }
                                break;
                            }
                        }
                    }
                }
            }
            if(!found) break;
        }

        while(true) {
            bool found = false;
            for(auto &e: tmp) {
                if(e != -1 && mp.find(e) == mp.end()) {
                    found = true;
                    int k, d;
                    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
                            if(grid[i][j] == e) k = i, d = j;
                    bool ok = true;
                    for(int i = 0; i < m; i++) if(i != k && grid[i][d] != e && grid[i][d] != '#')
                            ok = false;
                    if(ok) {
                        mp[e] = ii(1, d);
                        ans.push_back(e);
                        for (int i = 0; i < m; ++i) {
                            grid[i][d] = '#';
                        }
                    }
                    else {
                        ok = true;
                        for(int j = 0; j < n; j++) if(j != d && grid[k][j] != e && grid[k][j] != '#')
                                ok = false;
                        if(ok) {
                            mp[e] = ii(0, k);
                            ans.push_back(e);
                            for(int j = 0; j < n; j++) grid[k][j] = '#';
                        }
                    }
                }
            }
            if(!found) break;
        }
            cout << ans.back();
            for(int j = ans.size() - 2; j >= 0; j--) cout << " " << ans[j];
            cout << endl;

        }


    return 0;
}
