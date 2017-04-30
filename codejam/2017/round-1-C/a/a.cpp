//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
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

bool comp(ii f, ii s) {
    return f.first * f.second < s.first * s.second;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, k; cin >> n >> k;
        ll ans = 0;
        vii all(n);
        for(auto &e : all) cin >> e.first >> e.second;
        sort(all.begin(), all.end());
        for(int i = n - 1; i >= 0; i--) {
            vii rem;
            ll cur_ans = all[i].first * all[i].first + 2 * all[i].first * all[i].second;
            for(int j = i - 1; j >= 0; j--) rem.push_back(ii(all[j].second, all[j].first));
            sort(rem.begin(), rem.end(), comp);
            int r = k - 1, ind = rem.size() - 1;
            while(r) {
                if(ind < 0) break;
                cur_ans += 2 * rem[ind].first * rem[ind].second;
                ind--, r--;
            }
            if(!r)
                ans = max(ans, cur_ans);
        }
        cout << "Case #" << i <<": ";
        cout << fixed << setprecision(9) << acos(-1.) * ans << endl;
    }


    return 0;
}
