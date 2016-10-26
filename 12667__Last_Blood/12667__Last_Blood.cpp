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

int main() {
    ios::sync_with_stdio(0);
    vii sol;
    int n, t, m;
    cin >> n >> t >> m;
    sol.resize(n + 10, make_pair(-1, -1));
    set<pair<int, int>> st;
    for(int i = 0; i < m; i++) {
        int time, team;
        char pNum;
        string ver;
        cin >> time >> team  >> pNum >> ver;
        if(ver == "Yes") {
            ii tmp = make_pair(team, pNum - 65);
            if(st.find(tmp) == st.end()) {
                sol[pNum - 65] = make_pair(team, time);
                st.insert(tmp);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << (char) (i + 65) << ' ';
        if(sol[i].first != -1) cout << sol[i].second << ' ' << sol[i].first << endl;
        else  cout << "- -" << endl;

    }

    return 0;
}