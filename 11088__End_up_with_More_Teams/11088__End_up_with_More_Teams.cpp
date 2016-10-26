//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

bool func(int a, int b) { return a > b;}

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 1;
    while(cin >> n && n) {
        cout << "Case " << tc++ << ": ";
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        if(n < 3) {
            cout << "0\n";
            continue;
        }
        sort(nums.begin(), nums.end(), func);
        int ans = 0, tmp = 0;
        vector<bool> vis (nums.size(), false);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int j = n - 1;
            bool f = false;
            for(j; j > i; j--) {
                if(vis[j]) continue;
               for(int k = j - 1; k > i; k--){
                   if(vis[k]) continue;
                   if(nums[i] + nums[j] + nums[k] >= 20) {
                       ans++;
                       f = true;
                       vis[j] = vis[i] = vis[k] = true;
                       break;
                   }
                   else {
                       int tmp = k;
                       k = j;
                       j = tmp;
                   }
               }
                if(f) break;
            }

        }
        cout << ans << endl;
    }
    return 0;
}
