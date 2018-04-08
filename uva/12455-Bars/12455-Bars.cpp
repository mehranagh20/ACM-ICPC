#include <bits/stdc++.h>

using namespace std;

int nums[20], n, req;

int check(int i, int curr) {
    if(curr == req)
        return 1;
    for (int j = i + 1; j < n; j++) {
        if (curr + nums[j] == req)
            return 1;
        else if (curr + nums[j] < req)
            if (check(j, nums[j] + curr))
                return 1;
        else
            return 0;
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &req);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        sort(nums, nums + n);
        for(int i = 0; i < n; i++) {
            if(check(i, nums[i]) || !req) {
                printf("YES\n");
                break;
            }
            if(i == n - 1)
                printf("NO\n");
        }
    }
    return 0;
}