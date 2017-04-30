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
    int n, m, tc = 0;
    while(cin >> n >> m && (n || m)) {
        vi heights(n * m);
        for(auto &e: heights) cin >> e;
        sort(heights.begin(), heights.end());
        int cur_num = 0, cur_height = heights[0], water; cin >> water;
        double ans = cur_height;
        while(water) {
            while(cur_num < heights.size() && heights[cur_num] == cur_height) cur_num++;
            if(cur_num == heights.size()) ans += (double)water / (10 * 10 * cur_num), water = 0;
            else {
                int need = 10 * 10 * cur_num * (heights[cur_num] - cur_height);
                if(need > water) ans += (double)water / (10 * 10 * cur_num), water = 0;
                else
                    ans = heights[cur_num], water -= need;
                cur_height = heights[cur_num];
            }
        }
        int flooded = 0;
        for(int i = 0; i < heights.size(); i++) if(ans - heights[i] > eps)
            flooded++;
        cout << "Region " << ++tc << endl;
        cout << "Water level is " << fixed << setprecision(2) << ans << " meters." << endl;
        cout << fixed << setprecision(2) << (((double)flooded * 100) / (n * m)) << " percent of the region is under water." << endl << endl;
    }


    return 0;
}
