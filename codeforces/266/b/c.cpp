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

// author: Mehran

// solution:
// if first != second since there is at least two consecutive numbers in the range first...second, and it is obvious that they are
// relatively prime, so the gcd of those two is 1 so gcd of all numbers in the range is 1, otherwise gcd is a (or b, they are the same :D)

int main() {
    ios::sync_with_stdio(0);
    string first, second;
    while(cin >> first >> second)
        cout << (first == second ? first : "1") << endl;

    return 0;
}
