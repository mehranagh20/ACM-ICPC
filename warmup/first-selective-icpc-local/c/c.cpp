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

#include <bits/stdc++.h>
using namespace std;
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b){
    vector<int> p(a.size());
    int u, v;
    if (a.empty()) return;
    b.push_back(0);
    for (size_t i = 1; i < a.size(); i++){
// If next element a[i] is greater than last element of
// current longest subsequence a[b.back()], just push it at back of "b" and continue
        if (a[b.back()] < a[i]){
            p[i] = b.back();
            b.push_back(i);
            continue;
        }
// Binary search to find the smallest element referenced by b which is just bigger than a[i]
// Note : Binary search is performed on b (and not a).
// Size of b is always <=k and hence contributes O(log k) to complexity.
        for (u = 0, v = b.size()-1; u < v;){
            int c = (u + v) / 2;
            if (a[b[c]] < a[i]) u=c+1; else v=c;
        }
// Update b if new value is smaller then previously referenced value
        if (a[i] < a[b[u]]){
            if (u > 0) p[i] = b[u-1];
            b[u] = i;
        }
    }
    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main() {
    ios::sync_with_stdio(0);
    string str; cin >> str;
    vi tmp;
    for(auto &e: str) tmp.push_back(e);
    vi ans;
    find_lis(tmp, ans);
    cout << 26 - ans.size() << endl;
    return 0;
}
