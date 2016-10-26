//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int m, n, mi; cin >> m >> n >> mi;
        int des = 0, all = m * (m + 1) * n * (n + 1) / 4;
        vvi nums(m, vi(n));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
                cin >> nums[i][j];
                if(j) nums[i][j] += nums[i][j - 1];
            }
        for(int i = 0; i < n; i++) for(int j = i; j < n; j++) {
                int beg = 0, sum = 0;
                vi vec(m);
                for(int k = 0; k < m; k++) {
                    vec[k] = nums[k][j] - (i ? nums[k][i - 1] : 0);
                    sum += vec[k];
                    while(sum >= mi) {
                        des += m - k;
                        sum -= vec[beg++];
                    }
                }
            }
        int gc = gcd(des, all);
        cout << "Case " << i << ": " << des / gc << "/" << all / gc << endl;
    }

    return 0;
}