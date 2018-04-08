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
    while(tc--) {
        string s; cin >> s;
        vvi ind(26);
        int ans = 0;
        for(int i = 0; i < s.size(); i++) ind[s[i] - 'A'].push_back(i);
        for(char c = 'A'; c <= 'Z'; c++)
            for(char cc = 'A'; cc <= 'Z'; cc++)
                for(char ccc = 'A'; ccc <= 'Z'; ccc++) {
//                    if(c == cc || c == ccc || cc == ccc) continue;
                    int cur = -1;
                    auto it = upper_bound(ind[c - 'A'].begin(), ind[c - 'A'].end(), cur);
                    if(it == ind[c - 'A'].end() || *it <= cur) continue;
                    cur = *it;
                    it = upper_bound(ind[cc - 'A'].begin(), ind[cc - 'A'].end(), cur);
                    if(it == ind[cc - 'A'].end() || *it <= cur) continue;
                    cur = *it;
                    it = upper_bound(ind[ccc - 'A'].begin(), ind[ccc - 'A'].end(), cur);
                    if(it == ind[ccc - 'A'].end() || *it <= cur) continue;
                    ans++;
                }
        cout << ans << endl;
    }


    return 0;
}
