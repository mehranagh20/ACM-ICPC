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
    string s; cin >> s;
    map<char, int> mp;
    mp['R'] = 0;
    mp['B'] = 1;
    mp['Y'] = 2;
    mp['G'] = 3;
    vector<char> rev = {'R', 'B', 'Y', 'G'};
    vvi cons(s.size(), vi(4, 0));
    vi done(s.size(), 0);
    for(int i = 0; i < s.size(); i++) if(s[i] == '!') {
        for(int j = 0; j < 4; j++) cons[i][j] = 1;
        done[i] = 4;
    }
    vi ans = {0, 0, 0, 0};
    for(int i = 0; i < s.size(); i++) for(int j = 0; j < s.size(); j++) {
        if(s[j] != '!') {
            for(int k = j + 3; k > j; k--) if(k < s.size() && s[k] == '!' && cons[k][mp[s[j]]]) {
                cons[k][mp[s[j]]] = 0, done[k]--;
                if(done[k] == 1) {
                    for(int y = 0; y < 4; y++) if(cons[k][y]) {
                        ans[y]++;
                        s[k] = rev[y];
                    }
                }
            }

            for(int k = j - 3; k < j; k++) if(k >= 0 && s[k] == '!' && cons[k][mp[s[j]]]) {
                cons[k][mp[s[j]]] = 0, done[k]--;
                if(done[k] == 1) {
                    for(int y = 0; y < 4; y++) if(cons[k][y]) {
                        ans[y]++;
                        s[k] = rev[y];
                    }
                }
            }

        }
    }
    cout << ans[0];
    for(int i = 1; i < 4; i++) cout << " " << ans[i];
    return 0;
}
