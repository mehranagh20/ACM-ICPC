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

    int s;
    while (cin >> s && s) {
        int n = (sqrt(1 + 8 * s) - 1) / 2;
        while (n * (n + 1) / 2 <= s)
            n++;
        int sum = n * (n + 1) / 2;
        cout << sum - s << ' ' << n << endl;
    }

    return 0;
}