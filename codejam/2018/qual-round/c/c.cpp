//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
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

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000 + 1
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back


int main() {
    int tc; scanf("%d", &tc);
    for(int i = 1; i <= tc; i++) {
        int a; scanf("%d", &a);
        int n = sqrt(a);
        if(n * n != a) n++;
        n = max(n, 3);
        vvi grid(n, vi(n, 0));
        while(1) {
            int desi = 1, desj = 1, mx = 0;
            for (int i = 1; i < n - 1; i++)
                for (int j = 1; j < n - 1; j++) {
                    int cur = 0;
                    for(int k = i - 1; k <= i + 1; k++)
                        for(int k2 = j - 1; k2 <= j + 1; k2++)
                            cur += (grid[k][k2] == 0);
                    if(cur > mx)
                        mx = cur, desi = i, desj = j;
                }
            printf("%d %d\n", desi + 1, desj + 1);
            fflush(stdout);
            int res1, res2; scanf("%d%d", &res1, &res2);
            if(res1 == -1 && res2 == -1) {
                printf("You Sucked");
                fflush(stdout);
                return 0;
            }
            if(res1 == 0 && res2 == 0)
                break;

            grid[res1 - 1][res2 - 1] = 1;
        }
    }

    return 0;
}