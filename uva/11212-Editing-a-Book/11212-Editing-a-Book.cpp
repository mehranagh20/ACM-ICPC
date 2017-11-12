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
map<vi, int> mp;

int bfs(vi &init, map<vi, int> &dis, int mx_depth, bool check=false) {
    dis[init] = 0;
    queue<vi> q;
    q.push(init);
    while(!q.empty()) {
        vi cur = q.front(); q.pop();
        if(check && mp.find(cur) != mp.end())
            return mp[cur] + dis[cur];
        // if(dis[cur] >= mx_depth) continue;
        if(dis[cur] >= mx_depth) continue;
        for(int i = 0; i < n; i++) for(int j = i; j < n; j++) {
            for(int k = 0; k < n; k++) {
                vi tmp = cur;
                if(k < i) {
                    for(int r = k; r < i; r++) tmp[r + j - i + 1] = cur[r];
                    int ind = k;
                    for(int r = i; r <= j; r++) {
                        tmp[ind] = cur[r];
                        ind++;
                    }
                }
                if(k > j) {
                    for(int r = k; r > j; r--) tmp[r - j + i - 1] = cur[r];
                    int ind = k;
                    for(int r = j; r >= i; r--) {
                        tmp[ind] = cur[r];
                        ind--;
                    }
                }
                if(dis.find(tmp) == dis.end()) {
                    int dis_now = dis[cur] + 1;
                    dis[tmp] = dis_now;
                    q.push(tmp);
                }
            }
        }
    }
    return inf;
}

int main() {
    ios::sync_with_stdio(0);
    int tc = 0;
    while(cin >> n && n) {
        mp.clear();
        vi init(n), des(n);
        for(int i = 1; i <= n; i++) des[i - 1] = i;
        for(auto &e: init) cin >> e;
        map<vi, int> from_source;
        bfs(des, mp, 2);
        int ans = bfs(init, from_source, 2, true);
        cout << "Case " << ++tc << ": ";
        if(ans != inf) cout << ans << endl;
        else cout << 5 << endl;
    }

    return 0;
}
