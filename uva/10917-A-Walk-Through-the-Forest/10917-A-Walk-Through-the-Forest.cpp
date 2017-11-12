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
vvii AdjList;
vi dist;

vi memo;

ll solve(int id) {
    if(id == 2) return 1;
    int &now = memo[id];
    if(now != -1) return now;
    now = 0;
    for(auto &e: AdjList[id]) {
        int b = e.first;
        if(dist[b] < dist[id]) now += solve(b);
    }
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int m; cin >> m;
        AdjList.assign(n + 10, vii());
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            AdjList[a].push_back(ii(b, c));
            AdjList[b].push_back(ii(a, c));
        }

        int s = 2;
        dist.assign(n + 10, inf); dist[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s));
        while (!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue; // this is a very important check
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }

        memo.assign(n + 10, -1);
        cout << solve(1) << endl;


    }


    return 0;
}
