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


int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vi par(n + 1, 0);
    vi frees;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        if(!k) frees.push_back(i + 1);
        par[k] = i + 1;
    }
    vvi v(frees.size());
    for(int i = 0; i < frees.size(); i++) {
        v[i].push_back(frees[i]);
        int tmp = frees[i];
        while(par[tmp]) {
            v[i].push_back(par[tmp]);
            tmp = par[tmp];
        }
    }
    vi out(n + 1, -1);
    for(int i = 0; i < v.size(); i++) out[v[i].back()] = i;

    par.assign(n + 1, 0);
    frees.clear();
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        if(!k) frees.push_back(i + 1);
        par[k] = i + 1;
    }
    vvi v2(frees.size());
    for(int i = 0; i < frees.size(); i++) {
        v2[i].push_back(frees[i]);
        int tmp = frees[i];
        while(par[tmp]) {
            v2[i].push_back(par[tmp]);
            tmp = par[tmp];
        }
    }
    int ans = 0;
    vi used1(n, 0), used2(n, 0);

    for(int i = 0; i < v2.size(); i++) {
        if(out[v2[i].back()] != -1) {
            int k = out[v2[i].back()];
            used1[i] = 1, used2[k] = 1;
            int d1 = v2[i].size() - 1, d2 = v[k].size() - 1;
            while(d1 >= 0 && d2 >= 0 && v2[i][d1] == v[k][d2]) {
                d1--, d2--;
            }
            ans += d1 + 1;
            ans += d2 + 1;
        }
    }
    for(int i = 0; i < v.size(); i++) if(used2[i] == 0)
            ans += v[i].size() - 1;
    for(int i = 0; i < v2.size(); i++) if(used1[i] == 0)
            ans += v2[i].size() - 1;

    cout << ans << endl;



    return 0;
}
