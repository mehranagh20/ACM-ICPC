#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const int inf = 1000000000;

int total_dist;
vi dists;
vi prices;
vvi memo;
const int tank_size = 200;

int solve(int id, int gas) {
    vi &ddists = dists;
    vi &pprices = prices;
    if (gas < 0 || gas > 200)
        return inf;
    if (id == memo.size()) {
        if (gas >= tank_size / 2)
            return 0;
        return inf;
    }
    if (memo[id][gas] != -1)
        return memo[id][gas];
    int ans = inf;
    for(int i = 0; i <= tank_size && gas + i <= 200; i++)
        ans = min(ans, solve(id + 1, gas + i - dists[id + 1]) + prices[id] * i);
    return memo[id][gas] = ans;
}

int main() {
    //ios::sync_with_stdio(false);
    vi &ddists = dists;
    vi &pprices = prices;
    int t, tc = 0; cin >> t;
    while (t--) {
        if(tc++) cout << endl;
        cin >> total_dist;
        while(getchar() != '\n');
        dists.clear();
        prices.clear();
        memo.clear();
        string s;
        int prev_dist = 0, dist_sofar = 0;
        while (getline(cin, s) && !s.empty()) {
            stringstream ss;
            ss << s;
            int d, p; ss >> d >> p;
            int tmp = d;
            if(d < total_dist) {
                d -= prev_dist;
                prev_dist = tmp;
                dists.push_back(d);
                prices.push_back(p);
                memo.push_back(vi(tank_size, -1));
                dist_sofar += d;
            }
        }
        dists.push_back(total_dist - dist_sofar);
        int ans = solve(0, tank_size / 2 - dists[0]);
        if (ans != inf)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}