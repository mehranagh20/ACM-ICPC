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
    vii mine(10), oth(10);
    vi time(10);
    for(auto &e: mine) cin >> e.first >> e.second;
    for(int i = 0; i < 10; i++) cin >> oth[i].first >> oth[i].second >> time[i];
    int t = 0;
    for(int i = 0; i < 3; i++) {
        for(int i = 0; i < 10; i++) {
            if(t < time[i]) {
                time[i] = max(time[i], t + mine[i].first);
                t += mine[i].first + mine[i].second;
            }
            else {
                int r = (t - time[i]) / (oth[i].first + oth[i].second);
                int tt = max(t, time[i] + r * (oth[i].first + oth[i].second) + oth[i].first);
                t = tt + mine[i].first + mine[i].second;
                time[i] = max(time[i] + (r + 1) * (oth[i].first + oth[i].second), t - mine[i].second);
            }
        }
    }
    cout << t - mine[9].second << endl;


    return 0;
}
