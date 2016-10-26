//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f = 0;
    while(scanf("%d", &n) && n) {
        if(f++) puts("");
        vector<int> nums(n);
        for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
        sort(nums.begin(), nums.end());
        int res = 1, tmp = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) tmp++;
            else {
                res = max(tmp, res); tmp = 1;
            }
        }
        res = max(res, tmp);
        printf("%d\n", res);
        for(int i = 0; i < res; i++) {
            for (int j = i; j < n; j += res) printf("%s%d", j == i ? "" : " ", nums[j]);
            puts("");
        }
    }
    return 0;
}