//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define S second
#define pb push_back

vvi graph;

bool dfs(int i) {
    int num = 0;
    for(auto &e: graph[i]) if(graph[e].size() == 0) num++;
    else {
            if(!dfs(e)) return false;
        }
    return num >= 3;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int tmp; cin >> tmp;
        graph[tmp - 1].push_back(i + 1);
    }

    cout << (dfs(0) ? "Yes" : "No") << endl;


    return 0;
}
