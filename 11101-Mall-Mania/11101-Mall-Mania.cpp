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

int main() {
    ios::sync_with_stdio(0);
    vii moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int fn, sn;
    while(cin >> fn && fn) {
        queue<ii> queue1;
        vii tmp; tmp.reserve(8000);
        int mxI = -inf, mxJ = -inf;
        for(int i = 0; i < fn; i++) {
            int a, b; cin >> a >> b;
            tmp.push_back(ii(a, b));
            mxI = max(mxI, a); mxJ = max(mxJ, b);
            queue1.push(ii(a, b));
        }
        cin >> sn;
        for(int i = 0; i < sn; i++) {
            int a, b; cin >> a >> b;
            tmp.push_back(ii(a, b));
            mxI = max(mxI, a); mxJ = max(mxJ, b);
        }
        vvi dis(mxI + 10, vi(mxJ + 10, inf));
        vector<vector<bool>> grid(mxI + 10, vector<bool>(mxJ + 10, false));
        for(int i = 0; i < fn; i++) dis[tmp[i].first][tmp[i].second] = 0;
        for(int i = fn; i < fn + sn; i++) grid[tmp[i].first][tmp[i].second] = true;
        while(!queue1.empty()) {
            ii front = queue1.front(); queue1.pop();
            if(grid[front.first][front.second]) {
                cout << dis[front.first][front.second] << endl;
                break;
            }
            for(auto &e : moves) {
                int tmpI = e.first + front.first, tmpJ = e.second + front.second;
                if(tmpI < 0 || tmpI > mxI || tmpJ < 0 || tmpJ > mxJ || dis[tmpI][tmpJ] != inf) continue;
                dis[tmpI][tmpJ] = dis[front.first][front.second] + 1;
                queue1.push(ii(tmpI, tmpJ));
            }
        }
    }
    return 0;
}