#include <bits/stdc++.h>

using namespace std;

int nums[20], n, req, sumOfAns, sizeOfAns;
vector<int> tmp, ans;

void solution(int i, int j, int curr) {
        if ( curr > sumOfAns) {
            sumOfAns = curr;
            sizeOfAns = i;
            for (int d = 0; d <= i; d++)
                ans[d] = tmp[d];
        }
    for (int k = j + 1; k < n; k++) {
        if (curr + nums[k] <= req) {
            tmp[i + 1] = nums[k];
            solution(i + 1, k, curr + nums[k]);
        }
    }
}

int main() {
    tmp.resize(20);
    ans.resize(20);
    while (scanf("%d", &req) != EOF) {
        sumOfAns = 0;
        sizeOfAns = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        for (int i = 0; i < n; i++) {
            tmp[0] = nums[i];
            solution(0, i, nums[i]);
        }
        for (int i = 0; i <= sizeOfAns; i++)
            printf("%d ", ans[i]);
        printf("sum:%d\n", sumOfAns);
    }
    return 0;
}