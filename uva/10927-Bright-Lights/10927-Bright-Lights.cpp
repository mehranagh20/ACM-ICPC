//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))

bool comp(iii &a, iii &b){
    int &x1 = a.second.first, &x2 = b.second.first,
        &y1 = a.second.second, &y2 = b.second.second;
    if(y1 * x2 == x1 * y2)
        return ii(y1, abs(x1)) < ii(y2, abs(x2));

    return y1 * x2 < x1 * y2;
}

int main() {
    ios::sync_with_stdio(0);
    int n, k = 1;
    viii v;
    while(cin >> n && n){
        v.assign(n, iii());
        for(auto &e: v)
            cin >> e.second.first >> e.second.second >> e.first;

        sort(v.begin(), v.end(), comp);

        vii ans;
        int mxh = v[0].first;
        for (int i = 1; i < n; ++i) {

            while(v[i].second.second * v[i - 1].second.first == v[i].second.first * v[i - 1].second.second && i < n){
                if(v[i].first <= mxh)
                    ans.push_back(ii(v[i].second.first, v[i].second.second));

                mxh = max(mxh, v[i].first);
                i++;
            }

            mxh = v[i].first;
        }

        cout << "Data set " << k++ << ':' << endl;
        if(ans.size()){
            sort(ans.begin(), ans.end());
            cout << "Some lights are not visible:\n";
            for (int i = 0; i < ans.size(); ++i) {
                cout << "x = " << ans[i].first << ", y = " << ans[i].second;
                cout << (i == ans.size() - 1 ? ".\n" : ";\n");
            }
        }
        else
            cout << "All the lights are visible.\n";
    }

    return 0;
}
