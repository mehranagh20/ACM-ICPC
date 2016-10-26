//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vvi graph;
vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int r, c;
ii st, fi;

int bfs() {
    vvi dis(r, vi(c, inf)); dis[st.first][st.second] = 0;
    queue<ii> queue1; queue1.push(st);
    while(!queue1.empty()) {
        ii front = queue1.front(); queue1.pop();
        for(auto &e : moves)
            if(e.first + front.first >= 0 && e.first + front.first < r && e.second + front.second >= 0 && e.second + front.second < c) {
                if(!graph[e.first + front.first][e.second + front.second] || dis[e.first + front.first][e.second + front.second] != inf) continue;
                dis[e.first + front.first][e.second + front.second] = dis[front.first][front.second] + 1;
                ii tmp = ii(e.first + front.first, e.second + front.second);
                if(tmp == fi) return dis[tmp.first][tmp.second];
                queue1.push(tmp);
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> r >> c && (r || c)) {
        graph.clear(); graph.resize(r, vi(c, 1));
        int nR; cin >> nR;
        for(int i = 0; i < nR; i++) {
            int row; cin >> row;
            int bombNum; cin >> bombNum;
            for(int i = 0; i < bombNum; i++) {
                int col; cin >> col;
                graph[row][col] = 0;
            }
        }
        cin >> st.first >> st.second >> fi.first >> fi.second;
        cout << bfs() << endl;
    }
    return 0;
}