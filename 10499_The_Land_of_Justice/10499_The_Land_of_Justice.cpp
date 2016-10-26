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
    long long n;
    while(cin >> n && n > 0) {
        unsigned long long tmp = n;
        if(n == 1) cout << "0%\n";
        else
            cout << (25 * tmp) << "%\n";
    }
    return 0;
}