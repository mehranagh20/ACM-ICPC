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

vi vis;
string a, b;
string rec(int i) {
    if(i >= b.size())
        return "";
    int eq = -1;
    for (int j = 0; j < a.size(); ++j) {
        if(!vis[j] && a[j] == b[i]) eq = j;
    }
    if(eq != -1) {
        vis[eq] = 1;
        string an = rec(i + 1);
        if(an != "-1") return a[eq] + an;
        vis[eq] = 0;
    }
    vector<pair<char, int>> v;
    for (int j = 0; j < a.size(); ++j) {
        if (!vis[j]) if (a[j] < b[i]) {
            v.push_back(make_pair(a[j], j));
        }
    }
    sort(v.begin(), v.end());
    if (!v.size()) return "-1";
    vis[v.back().second] = 1;
    string str;
    for (int k = 0; k < a.size(); ++k) {
        if (!vis[k]) str += a[k];
    }
    sort(str.begin(), str.end());
    reverse(str.begin(), str.end());
    return v.back().first + str;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> a >> b;
    vis.resize(b.size() + 100, 0);
    if(b.size() > a.size()) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << a << endl;
    }
    else cout << rec(0) << endl;

    return 0;
}