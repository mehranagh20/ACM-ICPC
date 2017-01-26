#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    double a, b;
    while(cin >> a >> b) {
        int tmp = 0;
        while (a > 0) {
            a -= pow(2, tmp);
            tmp++;
        }
        if(tmp - 1 <= b) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}