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



int main() {
    ios::sync_with_stdio(0);
    vvi graph(11000, vi());
    vi last = {1}, cur;

    int len = 2, num = 2;
    while(num < 10000){
        cur.clear();
        for (int i = 0; i < len; ++i) {
            if(i == 0){
                graph[num + i].push_back(last[0]);
                graph[last[0]].push_back(num + i);
            }

            else if(i == len - 1){
                graph[num + i].push_back(last[i - 1]);
                graph[last[i - 1]].push_back(num + i);
            }

            else{
                graph[num + i].push_back(last[i - 1]);
                graph[num + i].push_back(last[i]);

                graph[last[i - 1]].push_back(num + i);
                graph[last[i]].push_back(num + i);
            }

            if(i){
                graph[num + i].push_back(num + i - 1);
                graph[num + i - 1].push_back(num + i);
            }

            cur.push_back(num + i);
        }

        num += len; len++;
        last = cur;
    }


    int s, t;
    while(cin >> s >> t && (s || t)){
        vi dis(11000, inf); dis[s] = 0;
        queue<int> q;
        q.push(s);

        while(dis[t] == inf){
            int u = q.front(); q.pop();
            for(auto &v: graph[u]){
                if(dis[v] != inf) continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }

        cout << dis[t] << endl;
    }

    return 0;
}
