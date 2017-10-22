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

viii adj;

vector<int> ufds;

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

int kruskal(viii &v) {
    int cost = 0;
    for(int i = 0; i < adj.size(); i++) {
        pair<int, ii> fr = adj[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            v.push_back(adj[i]);
            cost += fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    return cost;
}


int main() {
    ios::sync_with_stdio(0);
    int n, k, d;
    while(cin >> n >> k >> d && (n || k || d)) {
        vi di(n + 1, 0), ke, dii, kee(n + 1, 0);
        for(int i = 0; i < k; i++) {
            int a; cin >> a;
            ke.push_back(a);
            kee[a] = 1;
        }
        for(int i = 0; i < d; i++) {
            int a; cin >> a;
            di[a] = 1;
            dii.push_back(a);
        }

        adj.clear();
        for(auto &e: ke) {
            adj.push_back(iii(1, ii(0, e)));
//            else {
//                for(int i = e + 1; i <= n; i++) if(di[i]) {
//                        adj.push_back(iii(i - e + 1, ii(0, i)));
//                        break;
//                    }
//
//                for(int i = e - 1; i >= 1; i--) if(di[i]) {
//                        adj.push_back(iii(e - i + 1, ii(0, i)));
//                        break;
//                    }
//            }
        }
        si tmp;
        for(auto &e: ke) tmp.insert(e);
        for(auto &e: dii) tmp.insert(e);
        dii.clear();
        for(auto &e: tmp) dii.push_back(e);
        sort(dii.begin(), dii.end());
        for(int i = 1; i < dii.size(); i++) {
            if(!kee[dii[i]] || !kee[dii[i]]) {
                adj.push_back(iii(dii[i] - dii[i - 1], ii(dii[i], dii[i - 1])));
            }
        }
        buildUfds(n + 1);
        sort(adj.begin(), adj.end());
        viii adjl;
        int cost = kruskal(adjl);
        for(auto &e: ke) if(!di[e]) {
                int num = 0, w;
                for(auto &ee: adjl) if(ee.second.first == e || ee.second.second == e) {
                        num++;
                        w = ee.first;
                    }
                if(num == 1) cost -= w;
            }
        cout << cost << endl;

    }


    return 0;
}
