#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

//Do Not Use ios::sync_with_stdio(0) with getchar :\ idk why but will give you TLE :|
int solve(string &str) {
    if(!str.size()) return 1;
    for(int i = 0; i < str.size(); i++) {
        int sz = 0;
        for(int j = i; j < str.size(); j++) {
            if(str[i] == str[j]) sz++;
            else break;
        }
        if(sz > 1) {
            string tmpGp = str;
            tmpGp.erase(tmpGp.begin() + i, tmpGp.begin() + i + sz);
            if(solve(tmpGp)) return 1;
        }
        i += sz - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        string tmp; cin >> tmp;
        cout << solve(tmp) << endl;

    }
    return 0;
}