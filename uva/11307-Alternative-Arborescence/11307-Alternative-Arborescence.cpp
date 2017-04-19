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

vvi graph;
vvi memo;
int mx_color;

int solve(int id, int col) {
    int mn = inf;
    if(memo[id][col] != -1) return memo[id][col];
    for(int i = 1; i < mx_color; i++) if(i != col) {
        int x = i;
        for(auto &e : graph[id])
            x += solve(e, i);
        mn = min(mn, x);
    }
    return memo[id][col] = mn;
}
int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        cin.ignore();
        graph.assign(n, vi());
        vi root(n, 0);
        for(int i = 0; i < n; i++) {
            string line; getline(cin, line);
            stringstream ss(line);
            int a, b; char c;
            string str, num;
            ss >> str;
            int k = 0;
            while(isdigit(str[k])) {
                num += str[k];
                k++;
            }
            a = stoi(num);
            while(ss >> b) {
                root[b] = 1;
                graph[a].push_back(b);
            }
        }
        int r = 0;
        for(int i = 0; i < n; i++) if(!root[i]) {
            r = i;
            break;
        }
        mx_color = 10;
        memo.assign(n + 10, vi(11, -1));
        int mn = inf;
        for(int i = 0; i < mx_color; i++)
            mn = min(solve(r, i), mn);
        cout << mn << endl;
    }


    return 0;
}
