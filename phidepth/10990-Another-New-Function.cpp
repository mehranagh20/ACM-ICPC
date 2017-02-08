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
    vi numDiffPF(2 * 1e6 + 10, 0);
    for(int i = 1; i < numDiffPF.size(); i++) numDiffPF[i] = i;
    for (int i = 2; i < 2 * 1e6; i++)
        if (numDiffPF[i] == i) // i is a prime number
            for (int j = i; j < 2 * 1e6 + 10; j += i)
                numDiffPF[j] -= numDiffPF[j] / i ; // increase the values of multiples of
    //for(int i = 1; i <= 13; i++) cout << i << " " << numDiffPF[i] << endl;
    vi depth(2 * 1e6 + 10, 1);
    for(int i = 3; i <= depth.size(); i++)
        depth[i] = depth[numDiffPF[i]] + 1;
    for(int i = 2; i < depth.size(); i++) depth[i] += depth[i - 1];

    int tc; cin >> tc;
    while(tc--) {
        int a, b; cin >> a >> b;
        cout << depth[b] - depth[a - 1] << endl;
    }

    return 0;
}
