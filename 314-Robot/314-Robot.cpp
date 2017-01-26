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
int r, c, ori;
ii st, fi;
vvii moves = {{{1, 0}, {2, 0}, {3, 0}}, {{0, -1}, {0, -2}, {0, -3}}, {{-1, 0}, {-2, 0}, {-3, 0}}, {{0, 1}, {0, 2}, {0, 3}}};

//0, 1, 2, 3 south, west, north, east

ii newOri(int ori) {
    int fOri = ori - 1, sOri = ori + 1;
    if(fOri < 0) fOri = 3;
    if(sOri > 3) sOri = 0;
    return ii(fOri, sOri);
}

bool moveOk(ii st, ii fi) {
    if(graph[fi.first][fi.second] || graph[fi.first][fi.second - 1] || graph[fi.first - 1][fi.second - 1] || graph[fi.first - 1][fi.second]) return false;
    if(st.first == fi.first) {
        if(st.second > fi.second) swap(fi.second, st.second);
        for(int i = st.second; i <= fi.second; i++)
            if(graph[st.first - 1][i] || graph[st.first][i]) return false;
    }
    else {
        if(st.first > fi.first) swap(st.first, fi.first);
        for(int i = st.first; i <= fi.first; i++)
            if(graph[i][st.second - 1] || graph[i][st.second]) return false;
    }
    return true;
}

int bfs() {
    vvvi dis(r, vvi(c, vi(4, inf))); dis[st.first][st.second][ori] = 0;
    queue<iii> queue1; queue1.push(iii(ori, ii(st.first, st.second)));
    while(!queue1.empty()) {
        iii front = queue1.front(); queue1.pop();
        int ori = front.first, row = front.second.first, col = front.second.second;
        if(row == fi.first && col == fi.second)
            return dis[row][col][ori];
        for(auto &e : moves[ori]) {
            int tmpR = row + e.first, tmpC = col + e.second;
            if(tmpR < 1 || tmpR >= r || tmpC < 1 || tmpC >= c) continue;
            if(dis[tmpR][tmpC][ori] != inf || !moveOk(ii(row, col), ii(tmpR, tmpC))) continue;
            dis[tmpR][tmpC][ori] = dis[row][col][ori] + 1;
//            if(tmpR == fi.first && tmpC == fi.second)
//                return dis[tmpR][tmpC][ori];
            queue1.push(iii(ori, ii(tmpR, tmpC)));
        }
        ii nOri = newOri(ori);
        if(dis[row][col][nOri.first] == inf) {
            dis[row][col][nOri.first] = dis[row][col][ori] + 1;
            queue1.push(iii(nOri.first, ii(row, col)));
        }
        if(dis[row][col][nOri.second] == inf) {
            dis[row][col][nOri.second] = dis[row][col][ori] + 1;
            queue1.push(iii(nOri.second, ii(row, col)));
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> r >> c && (r || c)) {
        graph.clear(); graph.resize(r, vi(c));
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> graph[i][j];
        cin >> st.first >> st.second >> fi.first >> fi.second;
        string oriation; cin >> oriation;
        if(oriation == "south") ori = 0;
        if(oriation == "north") ori = 2;
        if(oriation == "west") ori = 1;
        if(oriation == "east") ori = 3;
        cout << bfs() << endl;
    }
    return 0;
}