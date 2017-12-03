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
    int n, t; cin >> n >> t;
    vi nums;
    int ans = 0;
    for(int i = 0; i < t; i++) {
        string str; cin >> str;
        int sec;
        if(str[0] == 'u') {
            cin >> sec;
            while(sec--) {
                int d = nums.back();
                ans = (ans - d) % n;
                ans = (ans + n) % n;
                nums.pop_back();
            }
        }
        else {
            sec = stoi(str);
            ans += (sec) % n;
            ans = (ans + n) % n;
            nums.push_back(sec);
        }
    }
    cout << ans << endl;


    return 0;
}
