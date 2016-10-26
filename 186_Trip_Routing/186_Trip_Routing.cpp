//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

void floyd(vvi &adjMat, vvi &path, int m) {
    for(int k = 0; k < m; k++) for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
                if(adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) {
                    path[i][j] = path[k][j];
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
}

void cr(int i, int j, vvi &path, vi &ans) {
    if(i != j) cr(i, path[i][j], path, ans);
    ans.push_back(j);
}

int main() {
    int ind = 0;
    string l;
    vvi graph(105, vi(105, inf)), path(105, vi(105)), rDis(105, vi(105, inf));
    map<string, int> mp;
    vector<string> rvMp;
    vector<vector<string>> route(105, vector<string>(105));
    while(getline(cin, l) && !l.empty()) {
        stringstream ss(l);
        string f, s, r;
        int c;
        getline(ss, f, ',');
        if(mp.find(f) == mp.end()){
            mp[f] = ind++;
            rvMp.push_back(f);
        }
        getline(ss, s, ',');
        if(mp.find(s) == mp.end()) {
            mp[s] = ind++;
            rvMp.push_back(s);
        }
        getline(ss, r, ',');
        int a = mp[f], b = mp[s];
        ss >> c;
        if(c < graph[a][b]) {
            route[a][b] = route[b][a] = r;
            graph[a][b] = graph[b][a] = c;
            rDis[a][b] = rDis[b][a] = c;
        }
    }
    for(int i = 0; i < ind; i++) for(int j = 0; j < ind; j++) path[i][j] = i;
    floyd(graph, path, ind);

    while(getline(cin, l), cin){
        if(l.empty()) continue;
        cout << endl << endl;
        cout << "From                 To                   Route      Miles\n"
                "-------------------- -------------------- ---------- -----\n";

        stringstream ss(l);
        string f, s;
        getline(ss, f, ',');
        getline(ss, s, ',');
        vi ans; cr(mp[f], mp[s], path, ans);
        for(int i = 0; i < ans.size() - 1; i++)
            cout << setw(21) << left << rvMp[ans[i]] << setw(21)
                 << rvMp[ans[i + 1]] << setw(11) << route[ans[i]][ans[i + 1]]
                 << setw(5) << right << rDis[ans[i]][ans[i + 1]] << endl;
        cout << setw(58) << "-----" << endl << setw(47) << "Total" << setw(11) << graph[mp[f]][mp[s]] << endl;
    }

    return 0;
}
