//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9
#define mx 10000

int main() {
    ios::sync_with_stdio(0);
    int curr, unlock, n, tc = 1;
    while(cin >> curr >> unlock >> n && (curr || unlock || n)) {
        cout << "Case " << tc++ << ": ";
        curr %= mx; unlock %= mx;
        vi nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        queue<int> queue1; queue1.push(curr);
        vi dis(10000, inf); dis[curr] = 0;
        bool found = false;
        while(!queue1.empty()) {
            int front = queue1.front(); queue1.pop();
            if(front == unlock) {
                cout << dis[unlock] << endl;
                found = true;
                break;
            }
            for(auto &e : nums) {
                int tmp = (e + front) % mx;
                if(dis[tmp] != inf) continue;
                dis[tmp] = dis[front] + 1;
                queue1.push(tmp);
            }
        }
        if(!found) cout << "Permanently Locked" << endl;
    }
    return 0;
}