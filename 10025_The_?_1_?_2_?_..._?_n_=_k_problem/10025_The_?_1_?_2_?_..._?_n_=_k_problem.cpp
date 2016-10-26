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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int tc, i = 0; cin >> tc;
    while(tc--) {
        if(i++) cout << endl;
        double num; cin >> num;
        if(!num) cout << 3 << endl;
        else {
            num = fabs(num);
            ll poss = (sqrt(1 + 8 * num) - 1) / 2 - 1;
            ll n = num;
            while ((poss * (poss + 1)) / 2 < floor(n)) poss++;
            ll tmp = (poss * (poss + 1)) / 2;
            while ((tmp - n) % 2) {
                poss++;
                tmp = (poss * (poss + 1)) / 2;
            }
            cout << poss << endl;
        }
    }

    return 0;
}