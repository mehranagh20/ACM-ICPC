//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        string seq; cin >> seq;
        int n = seq.size();
        string ans;
        int rep;
        bool add = false;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string tmp;
                int k = 0;
                while (j + k < n && seq[i + k] == seq[j + k]) {
                    tmp += seq[i + k];
                    k++;
                }
                if(tmp == ans && add) rep++;

                if(tmp.size() > ans.size() || (tmp.size() == ans.size() && tmp < ans)) {
                    add = true;
                    ans = tmp; rep = 2;
                }
            }
            add = false;
        }
        if(ans.size()) cout << ans << ' ' << rep << endl;
        else cout << "No repetitions found!\n";
    }
    return 0;
}