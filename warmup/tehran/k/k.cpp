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
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

vi memo;
int n;
vvi points;
int solve(int st) {
    if((st & (st - 1) == 0)) return 0;
    if(memo[st] != -1) return memo[st];
    memo[st] = 0;
    for(int i = 0; i < n; i++){
        if((st & (1 << i))) {
            for(int k = 0; k < n; k++) if(k != i) {
                    if(st & (1 << k)) {
                        memo[st] = max(memo[st], solve(st & (~(1 << k))) + points[i][k]);
                    }
                }
        }
    }
    return memo[st];
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        points.assign(n, vi(n));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> points[i][j];
        memo.assign((1 << (n + 1)), - 1);
        cout << solve((1 << (n)) - 1) << endl;
    }


    return 0;
}
