//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        if(n == 2) {
            cout << "2\n";
            continue;
        }
        int ans = 0;
        if((nums[0] < nums.back() && nums[0] < nums[1]) || nums[0] > nums.back() && nums[0] > nums[1]) ans++;
        if((nums.back() < nums[0] && nums.back() < nums[nums.size() - 2]) || (nums.back() > nums[0] && nums.back() > nums[nums.size() - 2])) ans++;
        for(int i = 1; i < nums.size() - 1; i++) if((nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) || (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])) ans++;
        cout << ans << endl;
    }

    return 0;
}