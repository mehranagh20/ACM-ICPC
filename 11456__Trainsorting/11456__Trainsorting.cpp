// In The Name Of God
#include<bits/stdc++.h>

using namespace std;

int nums[2010], ld[2010], li[2010];

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, ans = 0; cin >> n;
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = n - 1; i >= 0; i--) {
            li[i] = 1; ld[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) li[i] = max(li[i], li[j] + 1);
                else ld[i] = max(ld[i], ld[j] + 1);
            }
            ans = max(ans, ld[i] + li[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}