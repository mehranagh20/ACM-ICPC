#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

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
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define inf 1000000000
#define eps 1e-9

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

vector<string> gird;
int n, m;

iii bfs(int x, int y){
    queue<ii> q; q.push(ii(x, y));
    vvi dis(n, vi(m, inf)); dis[x][y] = 0;
    while(q.size()){
        ii u = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int p = u.first + dx[i], t = u.second + dy[i];
            if(p < 0 || p >= n || t < 0 || t >= m || gird[p][t] == '#') continue;
            if(dis[p][t] != inf) continue;
            dis[p][t] = dis[u.first][u.second] + 1;

            q.push(ii(p, t));
            if(gird[p][t] == 'A')
                return iii(dis[p][t], ii(p, t));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc, count; cin >> tc;
    while(tc--){
        cin >> m >> n; count = 0; cin.get();
        gird.assign(n, ""); vii v;
        for (int i = 0; i < n; ++i) {
            string str; getline(cin , str);
            for (int j = 0; j < str.size(); ++j) {
                char c = str[j];
                gird[i].push_back(c);
                if (c == 'S')
                    v.push_back(ii(i, j));
                if(c == 'A') count++;
            }
            for (int i = 0; i < m - str.size(); ++i)
                gird[i].push_back(' ');
        }

        int ans = 0;
        while(v.size() <= count){
            int minDis = inf;
            ii pos(0, 0);
            for(auto i: v) {
                iii d = bfs(i.first, i.second);
                if(d.first < minDis)
                    minDis = d.first, pos = d.second;
            }
            gird[pos.first][pos.second] = ' ';
            ans += minDis, v.push_back(pos);
        }

        cout << (ans == inf ? 0 : ans) << endl;

    }

    return 0;
}
