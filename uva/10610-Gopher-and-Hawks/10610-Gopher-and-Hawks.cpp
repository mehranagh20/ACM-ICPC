//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

bool func(double a, double b) {
    if(a > b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int v, s;
    while(cin >> v >> s && (v || s)) {
        double mx = v * s * 60;
        vdd tmp;
        string str;
        dd st, fi;
        cin >> st.first >> st.second >> fi.first >> fi.second;
        cin.get();
        vvi graph(2);
        tmp.push_back(dd(st.first, st.second));
        tmp.push_back(dd(fi.first, fi.second));
        if(sqrt(pow(st.first - fi.first, 2) + pow(st.second - fi.second, 2)) - eps <= mx) graph[0].push_back(1), graph[1].push_back(0);
        int ind = 2;
        while(getline(cin, str) && cin && !str.empty()) {
            double a, b;
            stringstream ss(str);
            graph.push_back(vi());
            ss >> a >> b;
            for(int i = 0; i < tmp.size(); i++)
                if(sqrt(pow(tmp[i].first - a, 2) + pow(tmp[i].second - b, 2)) - eps <= mx)
                    graph[ind].push_back(i), graph[i].push_back(ind);
            ind++;
            tmp.push_back(dd(a, b));
        }
        vi dis(tmp.size(), inf); dis[0] = 0;
        queue<int> queue1; queue1.push(0);
        while(!queue1.empty()) {
            int u = queue1.front(); queue1.pop();
            for(auto &e : graph[u]) if(dis[e] == inf) {
                    dis[e] = dis[u] + 1;
                    queue1.push(e);
                }
        }
        if(dis[1] != inf) cout << "Yes, visiting " << dis[1] - 1 << " other holes.\n";
        else cout << "No.\n";
    }


    return 0;
}