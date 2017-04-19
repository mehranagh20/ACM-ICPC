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
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        vvii graph(n);
        vi dis(n, inf);
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            graph[a].push_back(ii(b, c));
        }
        for(int i = 0; i < n - 1; i++) {
            bool up = false;
            for (int j = 0; j < n; j++)
                for (auto &e : graph[j]) if(dis[e.first] > e.second + dis[j]) {
                        up = true; dis[e.first] = e.second + dis[j];
                    }
            if(!up) break;
        }
        bool poss = false;
        for(int j = 0; j < n; j++) for(auto &e : graph[j])
                if(dis[e.first] > e.second + dis[j]) {
                    poss = true;
                    break;
                }
        if(poss) cout << "possible\n";
        else cout << "not possible\n";
    }

    return 0;
}
