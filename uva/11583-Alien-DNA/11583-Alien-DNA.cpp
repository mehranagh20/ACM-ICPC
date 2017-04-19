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
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<string> words(n);
        for(int i = 0; i < n; i++) {
            cin >> words[i];
            sort(words[i].begin(), words[i].end());
        }
        int ind = 0, cut = 0;
        while(true) {
            int mx = 1;
            for(auto &c : words[ind]) {
                int currMx = 1;
                for(int j = ind + 1; j < n; j++) {
                    if (binary_search(words[j].begin(), words[j].end(), c))
                        currMx++;
                    else break;
                }
                mx = max(mx, currMx);
            }
            if(ind + mx == n) {
                break;
            }
            cut++;
            ind += mx;
        }
        cout << cut << endl;
    }

    return 0;
}