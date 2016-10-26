//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vi ufds, ans;
vector<pair<int, ii>> graph;

void buildUfds(int n) {
    ufds.clear(); ufds.resize(n);
    for(int i = 0; i < n; i++) ufds[i] = i;
}

int findSet(int i) {
    return (ufds[i] == i) ? i : (ufds[i] = findSet(ufds[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void joinSets(int i, int j) {
    int a = findSet(i), b = findSet(j);
    if (a < b) ufds[a] = b;
    else ufds[b] = a;
}

void kruskal() {
    for(int i = 0; i < graph.size(); i++) {
        pair<double, ii> fr = graph[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            joinSets(fr.second.second, fr.second.first);
        }
        else ans.push_back(fr.first);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m && (n || m)) {
        graph.clear(); graph.resize(m);
        buildUfds(n);
        int total = 0;
        for(int i = 0; i < m; i++) {
            int a, b, dis; cin >> a >> b >> dis;
            total += dis;
            graph[i] = make_pair(dis, make_pair(a, b));
        }
        sort(graph.begin(), graph.end());
        ans.clear(); kruskal();
        if(!ans.size()) cout << "forest\n";
        else {
            cout << ans[0];
            for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
            cout << endl;
        }
    }
    return 0;
}