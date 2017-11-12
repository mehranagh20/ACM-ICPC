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
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int p, q; cin >> p >> q;
        long long max_ans = 0, min_ans = 0;
        int div_num = 1 << q;

        for(int i = 0; i < (1 << p); i++) { // try all possilbe numbers, if a bit is 0 we consider it 1, else it is 2
            string current_number;
            for(int j = 0; j < p; j++)
                if(i & (1 << j)) current_number += '2';
                else current_number += '1';
            long long num = stoll(current_number) ; // conver string to int
            if(num % div_num == 0) { // if num is divisible with 2 ^ q
                if(!min_ans) min_ans = num;
                max_ans = num;
            }

        }
        cout << "Case " << i << ": ";
        if(min_ans == 0) cout << "impossible" << endl;
        else if(min_ans == max_ans) cout << min_ans << endl;
        else cout << min_ans << " " << max_ans << endl;
    }


    return 0;
}
