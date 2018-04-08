//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vvi memo;
vi seq;

int solve(int i, int stat) {
    if(i == seq.size() - 1) return 0;
    if(memo[i][stat] != -inf) return memo[i][stat];
    memo[i][stat] = 0;
    if(stat) {
        if(seq[i + 1] > seq[i]) memo[i][stat] = max(memo[i][stat], solve(i + 1, 1) + 1);
        else memo[i][stat] = 0;
        return memo[i][stat];
    }
    else {
        for(int j = i + 1; j < seq.size(); j++) {
            if(seq[j] > seq[i]) {
                if(j == i + 1) memo[i][stat] = max(memo[i][stat], solve(j, 0) + 1);
                else memo[i][stat] = max(memo[i][stat], solve(j, 1) + 1);
            }
        }
        return memo[i][stat];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n; cin >> n;
        vi seq(n);
        for(int i = 0; i < n; i++) cin >> seq[i];
        int N, p, q, a, b, c, d, e, f, M;
        cin >> N >> p >> q >> a >> b >> c >> d >> e >> f >> M;
        vii intervals(N + 1);
        intervals[0] = ii(p, q);
        if(p > q) swap(intervals[0].first, intervals[0].second);
        for(int i = 1; i <= N; i++) {
           int tmpP = (a * intervals[i - 1].first + b * intervals[i - 1].second + c)%M, tmpQ = (d * intervals[i - 1].first + e * intervals[i - 1].second + f)%M;
            intervals[i] = ii(tmpP, tmpQ);
            if(intervals[i].first > intervals[i].second) swap(intervals[i].first, intervals[i].second);
        }
        int ans = 0;
        for(int i = 1; i < intervals.size(); i++) {
            //cout << intervals[i].first << ' ' << intervals[i].second << endl;
            int count = 0;
            for(int j = i; j <= i + seq.size() && j < intervals.size(); j++) {
                if(seq[j - i] > intervals[j].second || seq[j - i] < intervals[j].first) break;
                count++;
            }
            if(count == seq.size()) ans++;
        }
        cout << "Case " << i << ": ";
        cout << ans << endl;

    }


    return 0;
}