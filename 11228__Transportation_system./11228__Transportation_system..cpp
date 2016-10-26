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

vector<int> ufds;
vector<pair<double, ii>> graph;
double des;

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
    double road = 0, rail = 0;
    int states = 0;
    for(int i = 0; i < graph.size(); i++) {
        pair<double, ii> fr = graph[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            if(fr.first > des) {
                rail += fr.first;
                states++;
            }
            else road += fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    cout << states + 1 << " " << round(road) << " " << round(rail) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n; cin >> n >> des;
        buildUfds(n);
        vii coordinates(n);
        for(int i = 0; i < n; i++) cin >> coordinates[i].first >> coordinates[i].second;
        graph.clear();
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
                double dis = sqrt(pow(coordinates[i].first - coordinates[j].first, 2) + pow(coordinates[i].second - coordinates[j].second, 2));
                graph.push_back(make_pair(dis, make_pair(i, j)));
            }
        sort(graph.begin(), graph.end());
        cout << "Case #" << i << ": ";
        kruskal();


    }
    return 0;
}