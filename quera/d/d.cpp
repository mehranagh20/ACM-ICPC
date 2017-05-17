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


vii ff, hh;
int n;

vi cal_time(vi &ts, vi &t) {
    vi end(n, 0), fr(n);
    end[0] = t[ts[0]];
    for (int i = 1; i < n; i++)
        end[i] = end[i - 1] + t[ts[i]];
    for (int i = 0; i < n; i++)
        fr[ts[i]] = end[i];
    return fr;
}

int cal_score(vi &ts, vi &t) {
    int ans = 0;
    vi fr = cal_time(ts, t);
    for(auto &e: ff) ans += abs(fr[e.first] - fr[e.second]);
    for(auto &e: hh) ans += max(0, 15 - abs(fr[e.first] - fr[e.second]));
    return ans;
}

bool br(vi &ts, vvi &graph) {
    bool notok = false;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            int a = ts[i], b = ts[j];
            for(auto &e: graph[b]) if(e == a)
                    notok = true;
        }
    return notok;
}

int main() {
    ios::sync_with_stdio(0);
    int m, f, h; cin >> n >> m >> f >> h;
    vi t(n);
    for(auto &e: t) cin >> e;
    vvi graph(n);
    vi indegree(n, 0), vis(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b), indegree[b]++;
    }

//calculate indegree before running alg.

    vi ts;
    std::priority_queue<int, std::vector<int>, std::greater<int> > pQueue;
    for(int i = 0; i < n; i++) if(!indegree[i]) pQueue.push(i);
    while(!pQueue.empty()) {
        int top = pQueue.top();
        pQueue.pop();
        vis[top] = 1;
        ts.push_back(top);
        for(auto &e : graph[top]) {
            if(vis[e]) continue;
            indegree[e]--;
            if(!indegree[e]) pQueue.push(e);
        }
    }

    for (int i = 0; i < f; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        ff.push_back(ii(a, b));
    }
    for (int i = 0; i < h; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        hh.push_back(ii(a, b));
    }

    if(br(ts, graph) || ts.size() != n)
        cout << "varshekast shodin" << endl;
    else {
        int ans = cal_score(ts, t);
        bool found = true;
        while(found) {
            found = false;
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    swap(ts[i], ts[j]);
                    if(br(ts, graph)) {
                        swap(ts[i], ts[j]);
                        continue;
                    }
                    int now = cal_score(ts, t);
                    if(now < ans) found = true, ans = now;
                    else
                        swap(ts[i], ts[j]);
                }
            }

        }
        cout << ans << endl;
    }

    return 0;
}
