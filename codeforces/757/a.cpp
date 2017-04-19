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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    map<char, int> mp, inMp;
    string s = "Bulbasaur";
    for(auto &c : s) mp[c]++;
    string in; cin >> in;
    for(auto &e : in) inMp[e]++;
    int ans = inf;
    for(auto it = mp.begin(); it != mp.end(); it++) if(inMp.find(it->first) != inMp.end())
        ans = min(ans, inMp[it->first] / it->second);
    if(ans == inf) cout << 0 << endl;
    else
    cout << ans << endl;




    return 0;
}
