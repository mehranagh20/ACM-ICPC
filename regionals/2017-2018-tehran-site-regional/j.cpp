//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vvii graph;

int ways(int i, int p) {
    int tmp = 0;
    for(auto &e: graph[i]) if(e.first != p) {
            e.second = ways(e.first, i) + 1;
            tmp = max(tmp, e.second);
        }
    return tmp;
}

void bfs(int i, vi &dis) {
    queue<int> q; q.push(i);
    dis [i] = 0;
    while(q.size()) {
        int v = q.front(); q.pop();
        for(auto &e: graph[v]) if(dis[e.first] == -1) {
                dis[e.first] = dis[v] + 1;
                q.push(e.first);
            }
    }
}

bool ok(int i, int p, vi &dis, int d) {
    vi go;
    for(auto &e: graph[i]) if(e.first != p)
        if(e.second >= d) go.push_back(e.first);
    if(go.size() > 1) return false;
    if(go.size() == 0) return true;
    return ok(go[0], i, dis, d);
}

bool check(int i, int p, vi &dis, int d) {
    if(dis[i] <= d) return true;
    vi go;
    for(auto &e: graph[i])
            if(e.second >= d) go.push_back(e.first);
    if(go.size() == 1) return check(go[0], i, dis, d);
    else if(go.size() == 2) {
        int a = go[0], b = go[1];
        if(dis[a] < dis[i]) {
            if(ok(b, i, dis, d) || b == p)
                return check(a, i, dis, d);
            else return false;
        }
        else {
            if(ok(a, i, dis, d) || a == p)
                return check(b, i, dis, d);
            else return false;
        }
    }
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        graph.assign(n, vii());
        for(int i = 0; i < n - 1; i ++) {
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(ii(b, -1)), graph[b].push_back(ii(a, -1));
        }
        ways(n - 1, -1);
        ways(0, -1);
        vi dis(n, -1);
        bfs(0, dis);
        int l = 0, h = 3000, ans = 0;
        while(l <= h) {
            int mid = (l + h) / 2;
            if(check(n - 1, -1, dis, mid)) h = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << endl;
    }


    return 0;
}
