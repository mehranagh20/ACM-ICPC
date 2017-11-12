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

double cost;
bool cmp(iii a, iii b) {
    if(a.first == b.first) {
        double tmp = a.second.first + cost * a.second.second;
        double tmp2 = b.second.first + cost * b.second.second;
        return tmp < tmp2;
    }
    return a.first > b.first;

}

double ct(iii a, double x) {
    return a.second.first + x * a.second.second;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    viii teams;
    for(int i = 0; i < n; i++) {
        int m, a, b; cin >> m >> a >> b;
        teams.push_back(iii(m, ii(a, b)));

    }
    cost = 1200;
    sort(teams.begin(), teams.end(), cmp);
    vviii ranges;
    ranges.push_back({teams[0]});
    for(int i = 1; i < teams.size(); i++) {
        if(teams[i].first == ranges.back().back().first) ranges.back().push_back(teams[i]);
        else ranges.push_back({teams[i]});
    }
    map<iii, int> mp;
    for(int i = 0; i < n; i++) {
        if(i == 0) mp[teams[i]] = 1;
        else {
            if(teams[i].first == teams[i - 1].first && ct(teams[i], 1200) == ct(teams[i - 1], 1200)) mp[teams[i]] = mp[teams[i - 1]];
            else mp[teams[i]] = i + 1;
        }
    }

    int ans = 0;

    for(auto &r: ranges) {
        for(int i = 0; i < r.size(); i++) for(int j = i + 1; j < r.size(); j++) {
                cost = (double)(r[i].second.first - r[j].second.first) / (r[j].second.second - r[i].second.second);
                sort(teams.begin(), teams.end(), cmp);

                map<iii, int> mpp;
                for(int i = 0; i < n; i++) {
                    if(i == 0) mpp[teams[i]] = 1;
                    else {
                        if(teams[i].first == teams[i - 1].first && ct(teams[i], cost) - ct(teams[i - 1], cost) <= eps) mpp[teams[i]] = mpp[teams[i - 1]];
                        else mpp[teams[i]] = i + 1;
                    }
                }
                int tmp = 0;
                for(auto &e: teams) {
                    int cur_rant = mpp[e], rank = mp[e];
                    if(cur_rant > rank) tmp += -(rank - cur_rant) * (rank - cur_rant);
                    else tmp += (rank - cur_rant) * (rank - cur_rant);
                }
                ans = max(ans, tmp);
            }
    }
    cout << ans << endl;


    return 0;
}
