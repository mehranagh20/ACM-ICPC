#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

int t1, t2, an;
vvvi memo;
vector<pair<vi, vi>> sites;
vvvi anss;

int solve(int id, int NRem, int BRem) {
    if(NRem < 0 || BRem < 0) return inf;
    if(NRem == 0 && BRem == 0) return 0;
    int &cur = memo[id][NRem][BRem], sz = sites[id].first.size();
    if(cur != inf) return cur;
    int ans = inf;
    for(int i = 0; i < sz; i++) {
        int tmp = solve(id + 1, NRem - i, BRem - (sz - i - 1)) + sites[id].first[i] + sites[id].second[sz - i - 1];
        if(ans > tmp) {
            ans = tmp;
            anss[id][NRem][BRem] = i;
        }
    }
    return cur = ans;

}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> t1 >> t2 && (t1 || t2)) {
        int n; cin >> n;
        sites.clear();
        sites.resize(n);
        for(int i = 0; i < n; i++) {
            int num, tmp; cin >> num;
            sites[i].first.push_back(0); sites[i].second.push_back(0);
            for(int j = 0; j < num; j++) {
                cin >> tmp;
                sites[i].first.push_back(tmp);
            }
            for(int j = 0; j < num; j++) {
                cin >> tmp;
                sites[i].second.push_back(tmp);
            }
        }
        memo.clear(); anss.clear();
        memo.resize(n + 1, vvi(t1 + 1, vi(t2 + 1, inf))); anss.resize(n + 1, vvi(t1 + 1, vi(t2 + 1)));
        vvvi &tm = anss;
        an = solve(0, t1, t2);
        cout << an << endl;
        cout << anss[0][t1][t2];
        int tmp1 = t1, tmp2 = t2;
        t1 -= anss[0][tmp1][tmp2]; t2 -= sites[0].second.size() - anss[0][tmp1][tmp2] - 1;
        for(int i = 1; i < n; i++) {
            tmp1 = t1; tmp2 = t2;
            cout << " " << anss[i][tmp1][tmp2];
            t1 -= anss[i][tmp1][tmp2]; t2 -= sites[i].second.size() - anss[i][tmp1][tmp2] - 1;
        }
        cout << endl << endl;
    }
    return 0;
}