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

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);

    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        vvi dp(a.size() + 1, vi(b.size() + 1, 0));
        for (int i = 1; i <= a.size(); i++)
            for (int j = 1; j <= b.size(); j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        cout << dp[a.size()][b.size()] << endl;
    }

    return 0;
}