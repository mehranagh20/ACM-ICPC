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

vviii graph;
vvi memo;
int des;

int solve(int id, int h) {
    if(id == des) return 0;
    auto &now = memo[id][h];
    if(now != inf) return now;
    now = 500;
    for(auto &nei: graph[id]) {
        int a = h, b = nei.second.first;
        int add = ((a >= 18 && a <= 24 && b >= 18 && b <= 24 && a > b) || (a >= 1 && a <= 6 && b >= 1 && b <= 6 && b < a) || (b >= 18 && b <= 24 && a >= 1 && a <= 6));
        now = min(now, solve(nei.first, nei.second.second) + add);
    }
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, id = 0; cin >> n;
        map<string, int> mp;
        graph.assign(101, viii(0, iii(0, ii(0, 0))));
        for(int i = 0; i < n; i++) {
            string s1, s2; int a, b;
            cin >> s1 >> s2 >> a >> b;
            if(mp.find(s1) == mp.end()) mp[s1] = id++;
            if(mp.find(s2) == mp.end()) mp[s2] = id++;
            if(b > 12 || b < 1) continue;
            a = a % 24;
            if(a == 0) a = 24;
            b = (b + a) % 24;
            if(b == 0) b = 24;
            if((a >= 18 && a <= 24 && b >= 18 && b <= 24 && a <= b) || (a >= 1 && a <= 6 && b >= 1 && b <= 6 && a <= b) || (a >= 18 && a <= 24 && b >= 1 && b <= 6))
                graph[mp[s1]].push_back(iii(mp[s2], ii(a, b)));
        }
        string a, b; cin >> a >> b;
        if(mp.find(a) == mp.end()) mp[a] = id++;
        if(mp.find(b) == mp.end()) mp[b] = id++;
        int aa = mp[a], bb = mp[b];
        memo.assign(id + 10, vi(30, inf));
        des = bb;
        int ans = solve(aa, 18);
        cout << "Test Case " << i << ".\n";
        if(ans == 500) cout << "There is no route Vladimir can take.\n";
        else cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
    }



    return 0;
}
