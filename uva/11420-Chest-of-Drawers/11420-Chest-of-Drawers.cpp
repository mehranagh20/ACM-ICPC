#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<llu> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vvvi memo;
int n, s;

llu solve(int id, int pr, int num) {
    if(num > s) return 0;
    if(id == n) return num == s ? 1 : 0;
    llu &tmp = memo[id][num][pr];
    if(tmp != inf) return tmp;
    if(pr == 0) tmp = solve(id + 1, 0, num + 1) + solve(id + 1, 1, num); // previous is locked
    else tmp = solve(id + 1, 0, num) + solve(id + 1, 1, num);
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    vvi mm(66, vi(66, inf));
    while(cin >> n >> s && (n >= 0 || s >= 0)) {
        if(mm[n][s] != inf) cout << mm[n][s] << endl;
        else {
            memo.clear();
            memo.resize(n + 4, vvi(s + 4, vi(2, inf)));
            mm[n][s] = solve(0, 0, 0); cout << mm[n][s] << endl;
        }
    }
    return 0;
}