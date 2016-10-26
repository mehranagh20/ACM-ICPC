#include <bits/stdc++.h>
using namespace std;

int arr[80][80];

long long kadane(vector<int> &nums) {
    long long ans = -1000000000, tmp = 0;
    for(int i = 0; i < nums.size(); i++) {
        tmp += nums[i]; ans = max(ans, tmp);
        if(tmp < 0) tmp = 0;
    }
    tmp = 0;
    for(int i = 0; i < nums.size(); i++) {
        tmp += nums[i]; long long tmp2 = tmp;
        for(int j = nums.size() - 1; j > i; j--) {
            tmp2 += nums[j];
            ans = max(ans, tmp2);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int TC; cin >> TC;
    while(TC--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                if (j) arr[i][j] += arr[i][j - 1];
            }
        long long ans = -1000000000;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                vector<int> nums1, nums2;
                for (int k = 0; k < n; k++) {
                    nums1.push_back(i ? arr[k][j] - arr[k][i - 1] : arr[k][j]);
                    if(i != j)
                        nums2.push_back(arr[k][i] + arr[k][n - 1] - arr[k][j - 1]);
                }
                ans = max(ans, kadane(nums1));
                if(i != j) ans = max(ans, kadane(nums2));

            }
        cout << ans << endl;
    }

    return 0;
}