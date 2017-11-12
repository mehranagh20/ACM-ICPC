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
    for(int k = 1; k <= tc; k++) {
        int n; cin >> n;
        vi all(n);
        for(auto &e: all) cin >> e;
        sort(all.begin(), all.end());
        deque<int> q;
        int i = 0, j = n - 2;
        q.push_back(all[n - 1]);
        while(i <= j) {
                int iif = abs(all[i] - q.front()), iib = abs(all[i] - q.back()), jjf = abs(all[j] - q.front()), jjb = abs(all[j] - q.back());
                if(iif > jjf) q.push_front(all[i]);
                else q.push_front(all[j]);
                if(iib > jjb) q.push_back(all[i]);
                else q.push_back(all[j]);
                if(abs(q[0] - q[1]) < abs(q.back() - q[q.size() - 2])) {
                    q.pop_front();
                    if(q.back() == all[i]) i++;
                    else j--;
                }
                else {
                    q.pop_back();
                    if(q.front() == all[i]) i++;
                    else j--;
                }

        }
        int ans = 0;
        cout << "Case " << k << ": ";
        for(int i = 1; i < q.size(); i++) ans += abs(q[i] - q[i - 1]);
        cout << ans << endl;
    }


    return 0;
}
