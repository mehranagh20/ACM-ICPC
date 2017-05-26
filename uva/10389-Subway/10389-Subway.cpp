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

#define inf 100000000
#define eps 1e-9

double dist(ii a, ii b){
    return sqrt(pow(a. first - b.first, 2) + pow(a.second - b.second, 2));
}

typedef pair<int, double> id;

map<ii, int> m;
vvii v;
vector<vector<pair<int, double>>> graph;

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc; cin.get();
    string line; getline(cin, line);

    bool f = true;
    while(tc--){
        int ind = 0;
        getline(cin, line);
        stringstream ss(line);
        int a, b; ii s, t;
        ss >> a >> b;
        m[ii(a, b)] = ind++;
        s = ii(a, b);

        ss >> a >> b;
        m[ii(a, b)] = ind++;
        t = ii(a, b);

        while(getline(cin, line) && line.size()){
            stringstream ss(line);
            v.push_back(vii());
            while(ss >> a >> b && !(a == -1 && b == -1)){
                m[ii(a, b)] = ind++;
                v.back().push_back(ii(a, b));
            }
        }

        graph.assign(ind, vector<pair<int, double>>());

        for(auto &line: v){
            for (int i = 0; i < line.size() -1; ++i) {
                graph[m[line[i]]].push_back(id(m[line[i + 1]], (dist(line[i], line[i + 1]) / 4) * 3.6));
                graph[m[line[i + 1]]].push_back(id(m[line[i]], (dist(line[i], line[i + 1]) / 4) * 3.6));
            }
        }

        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {


                for (int k = 0; k < v.size(); ++k) {
                    if(k == i) continue;
                    for (int l = 0; l < v[k].size(); ++l) {
                        graph[m[v[i][j]]].push_back((id(m[v[k][l]], (dist(v[i][j], v[k][l]) / 1) * 3.6)));
                    }
                }

                for (int l = 0; l < v[i].size(); ++l) {
                    if(abs(l - j) <= 1) continue;
                    graph[m[v[i][j]]].push_back((id(m[v[i][l]], (dist(v[i][j], v[i][l]) / 1) * 3.6)));
                }

            }
        }

        for(auto &line: v){
            for (int i = 0; i < line.size(); ++i) {
                graph[0].push_back(id(m[line[i]], (dist(line[i], s) / 1) * 3.6));
                graph[m[line[i]]].push_back(id(1, (dist(line[i], t) / 1) * 3.6));
            }
        }

        graph[0].push_back(id(1, (dist(s, t) / 1) * 3.6));

        int n = ind;
        typedef pair<double, int> di;

        vd dist(n, inf); dist[0] = 0;
        priority_queue<di, vector<di>, greater<di> > pq;
        pq.push(di(0, 0));
        while (!pq.empty()) {
            di front = pq.top(); pq.pop();
            double d = front.first; int u = front.second;
            if (d > dist[u]) continue; // this is a very important check
            for (int j = 0; j < (int) graph[u].size(); j++) {
                di v = graph[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(di(dist[v.first], v.first));
                }
            }
        }

        if(f) f = false;
        else cout << endl;

        cout << (int)round(dist[1] / 600) << endl;
        m.clear();
        v.clear();
    }
    return 0;
}
