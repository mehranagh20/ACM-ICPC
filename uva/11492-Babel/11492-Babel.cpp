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
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int ind = 0;
        map<string, int> mp;
        bool same = false;
        string f, s, tmp; cin >> f >> s;
        if(f == s) same = true;
        mp.insert(make_pair(f, ind++)); mp.insert(make_pair(s, ind++));
        vector<vector<pair<int, pair<short int, char>>>> graph;
        for(int i = 0; i < n; i++) {
            cin >> f >> s >> tmp;
            if(mp.find(f) == mp.end()) mp.insert(make_pair(f, ind++));
            if(mp.find(s) == mp.end()) mp.insert(make_pair(s, ind++));
            int ff = mp[f], ss = mp[s];
            while(graph.size() < ff + 1 || graph.size() < ss + 1) graph.push_back(vector<pair<int, pair<short int, char>>>());
            graph[ff].push_back(make_pair(ss, make_pair(tmp.size(), tmp[0])));
            graph[ss].push_back(make_pair(ff, make_pair(tmp.size(), tmp[0])));
        }
        vvi dis(ind, vi(70, inf)); dis[0][4] = 0;
        int ans = inf;
        priority_queue<pair<int, pair<char, int>>, vector<pair<int, pair<char, int>>>, greater<pair<int, pair<char , int>>>> queue1;
        queue1.push(make_pair(0, make_pair('@', 0)));
        while(!queue1.empty()) {
            int n = queue1.top().second.second, d = queue1.top().first;
            char curr = queue1.top().second.first;
            if(n == 1) {
                ans = dis[n][curr - 60];
                break;
            }
            queue1.pop();
            if(dis[n][curr - 60] < d) continue;
            for(auto &e : graph[n]) {
                if(e.second.second == curr) continue;
                if(dis[e.first][e.second.second - 60] > e.second.first + d) {
                    dis[e.first][e.second.second - 60] = e.second.first + d;
                    queue1.push(make_pair(dis[e.first][e.second.second - 60], make_pair(e.second.second, e.first)));
                }
            }
        }
        if(same) cout << "0" << endl; else {
            if (ans == inf) cout << "impossivel\n";
            else cout << ans << endl;
        }
    }

    return 0;
}