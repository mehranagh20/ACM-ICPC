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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n;
    cout << "PERFECTION OUTPUT\n";
    while(cin >> n && n) {
        int dSum = n == 1 ? 0 : 1;
        for(int i = 2; i <= n / 2; i++) if(n % i == 0)
                dSum += i;
        cout << setw(5) << right << n;
        if(dSum == n) cout << "  PERFECT\n";
        else if(dSum > n) cout << "  ABUNDANT\n";
        else cout << "  DEFICIENT\n";
    }
    cout << "END OF OUTPUT\n";
}