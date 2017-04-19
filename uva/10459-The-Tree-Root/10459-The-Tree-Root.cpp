//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int n, mx;
vector<bool> vis;
vvi graph;

void dfs(int i, int d) {
    vis[i] = true;
    for(auto &e : graph[i]) if(!vis[e]) {
            mx = max(mx, d + 1);
            dfs(e, d + 1);
        }
}

void fi(int i, int d, vi &li) {
    vis[i] = true;
    for(auto &e : graph[i]) if(!vis[e]) {
            if(d + 1 == mx) li[e] = 1;
            fi(e, d + 1, li);
        }
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n) {
        graph.clear(); graph.resize(n);
        for (int i = 0; i < n; i++) {
            int nn;
            cin >> nn;
            for (int j = 0; j < nn; j++) {
                int tmp; cin >> tmp; tmp--;
                graph[i].push_back(tmp);
            }
        }

        vi del(n, 0);
        int rem = n, lvl = 0;
        while(++lvl) {
            for(int i = 0; i < n; i++) if(!del[i]) {
                    int par = 0;
                    for(auto &e : graph[i]) if(del[e] == lvl || del[e] == 0) par++;
                    if(par == 1) del[i] = lvl, rem--;
                }
            if(rem == 2 || rem == 1) break;
        }
        vi best, worst, tmp(n, 0);
        for(int i = 0; i < n; i++) if(!del[i]) best.push_back(i);

        vis.clear(); vis.resize(n, 0);
        mx = -inf;
        dfs(best[0], 0);
        for(auto &e : best) {
            vis.clear(); vis.resize(n, 0);
            fi(e, 0, tmp);
        }
        for(int i = 0; i < n; i++) if(tmp[i]) worst.push_back(i);

        sort(best.begin(), best.end()); sort(worst.begin(), worst.end());
        cout << "Best Roots  :";
        for(int i = 0; i < best.size(); i++) cout << " " << best[i] + 1;
        cout << endl;
        cout << "Worst Roots :";
        for(int i = 0; i < worst.size(); i++) cout << " " << worst[i] + 1;
        cout << endl;
    }

    return 0;
}