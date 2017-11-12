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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 1;
    while(cin >> n) {
        vector<long long> numbers(n);
        for(auto &e: numbers) cin >> e;
        long long max_sum = 0;
        for(int i = 0; i < n; i++) for(int j = i; j < n; j++) {
            long long tmp = 1;
            for(int k = i; k <= j; k++)
                tmp *= numbers[k];
            max_sum = max(max_sum, tmp);
        }
        cout << "Case #" << tc++ << ": " << "The maximum product is " << max_sum << "." << endl << endl;
    }


    return 0;
}
