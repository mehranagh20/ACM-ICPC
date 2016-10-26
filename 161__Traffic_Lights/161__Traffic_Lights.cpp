//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int main() {
    int f, s, t;
    while(cin >> f >> s >> t && (f || s || t)) {
        vi times = {f, s};
        int m = inf;
        m = min(m, f); m = min(m, s);
        while(t) {
            m = min(m, t);
            times.push_back(t); cin >> t;
        }
        int ans = -1;
        for(int i = m + 1; i <= 18000; i++) {
            bool found = true;
            for(auto &e : times) {
                if((i / e) % 2 != 0 || ((i % e) >= e - 5)) {
                    found = false;
                    break;
                }
            }
            if(found) {
                ans = i; break;
            }
        }
        if(ans != -1) {
            int h = ans / 3600, min = (ans % 3600) / 60, s = (ans % 60);
            cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0')<< s << endl;
        }
        else cout << "Signals fail to synchronise in 5 hours" << endl;
    }
    return 0;
}