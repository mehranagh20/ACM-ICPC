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
vs grid;
vvi ind;
int w, h;
vii nei = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vii dignei = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vvi graph;

bool pos(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

void bfs(int i, int j) {
    int indd = ind[i][j];
    vvi dis(h, vi(w, -1));
    dis[i][j] = 0;
    queue<ii> q; q.push(ii(i, j));
    while(q.size()) {
        ii cur = q.front(); q.pop();
        int now_dis = dis[cur.first][cur.second];
        for(auto &e: nei) {
            int tmp_i = cur.first + e.first, tmp_j = cur.second + e.second;
            if(tmp_i < 0 || tmp_i >= h || tmp_j < 0 || tmp_j >= w || grid[tmp_i][tmp_j] == '#' || grid[tmp_i][tmp_j] == '*' || grid[tmp_i][tmp_j] == '~') continue;
            if(dis[tmp_i][tmp_j] == -1) {
                dis[tmp_i][tmp_j] = now_dis + 1;
                if(grid[tmp_i][tmp_j] == '!' || grid[tmp_i][tmp_j] == '@') {
//                    graph[ind[tmp_i][tmp_j]].push_back(ii(indd, now_dis + 1));
                    graph[indd][ind[tmp_i][tmp_j]] = now_dis + 1;
                }
                q.push(ii(tmp_i, tmp_j));
            }

        }
    }
}

vvi memo;
int n;

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
    if(bitmask == (1 << n) - 1)
        return graph[pos][0];
    if (memo[pos][bitmask] != inf)
        return memo[pos][bitmask];
    int &ans = memo[pos][bitmask];
    for (int nxt = 0; nxt < n; nxt++) // O(n) here
        if (graph[pos][nxt] != inf && nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
            ans = min(ans, graph[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> h >> w && (w || h)) {
        int num = 1;
        grid.assign(h, string());
        ind.assign(h, vi(w, -1));
        for(int i = 0; i < h; i++) {
            cin >> grid[i];
            for(int j = 0; j < w; j++)
                if(grid[i][j] == '!') ind[i][j] = num++;
                else if(grid[i][j] == '@') ind[i][j] = 0;
        }
        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
                if(grid[i][j] == '*') {
                    for(auto &e: nei) if(pos(i + e.first, j + e.second))
                        if(grid[i + e.first][j + e.second] != '*') grid[i + e.first][j + e.second] = '#';
                    for(auto &e: dignei) if(pos(i + e.first, j + e.second))
                        if(grid[i + e.first][j + e.second] != '*') grid[i + e.first][j + e.second] = '#';

                }
            }
        vs &tmp = grid;
        int cur_num = 0;
        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
                if(grid[i][j] == '!' || grid[i][j] == '@') cur_num++;
            }
        if(cur_num != num) cout << -1 << endl;
        else {
            graph.assign(num, vi(num, inf));
            for(int i = 0; i < h; i++) for(int j = 0; j < w; j++)
                    if(grid[i][j] == '!' || grid[i][j] == '@') bfs(i, j);
            for(int i = 0; i < graph.size(); i++) graph[i][i] = 0;
//            for(int i = 0; i < graph.size(); i++) {
//                for(int j = 0; j < graph.size(); j++) cout << graph[i][j] << " ";
//                cout << endl;
//            }
            n = graph.size();
            memo.assign(n + 1, vi((1 << 12), inf));
            int ans = tsp(0, 1);
            if(ans < inf) cout << ans << endl;
            else cout << -1 << endl;
        }
    }


    return 0;
}
