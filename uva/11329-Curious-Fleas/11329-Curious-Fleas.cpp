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

vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs(vs init) {
    map<pair<vs, bool>, int> dis;
    queue<pair<vs, bool>> q;
    dis[pair<vs, bool>(init, false)] = 0; q.push(pair<vs, bool>(init, false));
    while(!q.empty()) {
        vs cur = q.front().first; bool emp = q.front().second; q.pop();
        int num = 0, cur_i, cur_j;
        for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
            if(cur[i][j] == 'X') num++;
            else if(cur[i][j] == 'D') cur_i = i, cur_j = j;
        }
        if(num == 0) return dis[pair<vs, bool>(cur, emp)];
        for(auto &e: moves) {
            if(cur_i + e.first < 0 || cur_i + e.first >= 4 || cur_j + e.second < 0 || cur_j + e.second >= 4)
                continue;
            vs tmp = cur;
            tmp[cur_i][cur_j] = '.';
            if(emp)
                tmp[cur_i][cur_j] = 'X';
            bool next_emp = (cur[cur_i + e.first][cur_j + e.second] == '.');
            tmp[cur_i + e.first][cur_j + e.second] = 'D';
            if(dis.find(pair<vs, bool>(tmp, next_emp)) == dis.end()) {
                dis[pair<vs, bool>(tmp, next_emp)] = dis[pair<vs, bool>(cur, emp)] + 1;
                q.push(pair<vs, bool>(tmp, next_emp));
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    while(n--) {
        vs init(4);
        for(int i = 0; i < 4; i++) cin >> init[i];
        int ans = bfs(init);
        if(ans == -1) cout << "impossible" << endl;
        else cout << ans << endl;
    }


    return 0;
}
