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
    int n; cin >> n;
    vi order(n), sorder(n);
    for(int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
        sorder[order[i]] = i;
    }
    int tmp;
    while(cin >> tmp) {
        int ind = 0;
        vi seq(n), lis;
        seq[tmp - 1] = ind++;
        for(int i = 1; i < n; i++) {
            cin >> tmp;
            seq[tmp - 1] = ind++;
        }
        int mx = -inf;
        for(int i = 0; i < n; i++) {
            lis.push_back(1);
            for (int j = i - 1; j >= 0; j--) {
                if (order[seq[j]] < order[seq[i]] && lis[j] + 1 > lis.back()) lis.back() = lis[j] + 1;
            }
            mx = max(mx, lis.back());
        }
        cout << mx << endl;
    }

    return 0;
}