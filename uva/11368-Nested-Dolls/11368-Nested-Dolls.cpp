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

bool compare(ii a, ii b) {
    if(a.first < b.first) return true;
    if(a.first == b.first && a.second > b.second) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vii dolls(n);
        for(auto &e: dolls) cin >> e.first >> e.second;
        sort(dolls.begin(), dolls.end(), compare);
        vi flag(n, 0);
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(flag[i]) continue;
            flag[i] = 1;
            ans++;
            int w = dolls[i].first, h = dolls[i].second;
            for(int j = i - 1; j >= 0; j--) {
                if(flag[j] || dolls[j].first >= w || dolls[j].second >= h) continue;
                w = dolls[j].first, h = dolls[j].second;
                flag[j] = 1;

            }
        }
        cout << ans << endl;
    }


    return 0;
}
