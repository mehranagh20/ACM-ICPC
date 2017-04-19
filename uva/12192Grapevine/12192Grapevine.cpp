#include<bits/stdc++.h>

using namespace std;

int main() {
    int nums[505][505];
    int n, m;
    while(scanf("%d%d", &n, &m) && m && n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &nums[i][j]);
        int ans = 0, q;
        scanf("%d", &q);
        while(q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            for (int i = 0; i < n && n - i + 1 > ans; i++) {
                int j = lower_bound(nums[i], nums[i] + m, l) - nums[i], tmpI = i, tmpAns = 1;
                if(j >= m || m - j + 1 <= ans || nums[i][j] > r)
                    continue;
                while(nums[++tmpI][++j] <= r && tmpI < n && j < m)
                    tmpAns++;
                if(tmpAns > ans)
                    ans = tmpAns;
            }
            printf("%d\n", ans); ans = 0;
        }
        puts("-");
    }

    return 0;
}