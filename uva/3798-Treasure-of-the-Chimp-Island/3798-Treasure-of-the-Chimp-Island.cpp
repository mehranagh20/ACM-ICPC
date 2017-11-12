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

int n;
vs grid;

vii moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dijkstra(int i, j, d) {
    vvvi dis(n + 10, vvi(n + 10, vi(100, inf)));
    dis[i][j][d] = 0;
    priority_queue<iii> q; q.push(iii(d, ii(i, j)));
    while(!q.empty()) {
        iii cur = q.front(); q.pop();
        i = cur.second.first, j = cur.second.second, d = cur.first;
        for(auto &nei: moves) if(i + e.first >= 0 && i + e.first < n && j + e.second >= 0 && j + e.second < n) {
            int ci = i + e.first, cj = j + e.second;
            if(isalpha(grid[ci][cj]) || grid[ci][cj] == '#' || grid[ci][cj] == '*') continue;
            if(dis[ci][cj][d] != inf) continue;
            if(grid[ci][cj] == '.') {
                dis[ci][cj][d] = dis[i][j][d];
                q.push(iii(d, ii(ci, cj)));
            }
            else if(isdigit(grid[ci][cj])) {
                if(d) {
                    if(dis[ci][cj][d - 1] != inf) continue;
                    dis[ci][cj][d - 1] = dis[ci][cj][d];
                    q.push(iii())
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);


    return 0;
}
