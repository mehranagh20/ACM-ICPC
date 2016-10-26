// In The Name Of God
#include<bits/stdc++.h>

using namespace std;
int height[10000], width[10000], ld[10000], li[10000];

int main() {
    int tc; scanf("%d", &tc);
    for(int i = 0; i < tc; i++) {
        int n, dMax = 0, iMax = 0; scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &height[i]);
        for(int i = 0; i < n; i++) scanf("%d", &width[i]);
        for(int i = 0; i < n; i++) {
            ld[i] = li[i]= width[i];
            for(int j = i - 1; j >= 0; j--) {
                if(height[i] > height[j])
                    li[i] = max(li[i], li[j] + width[i]);
                else if(height[i] < height[j])
                    ld[i] = max(ld[i], ld[j] + width[i]);
            }
            dMax = max(dMax, ld[i]);
            iMax = max(iMax, li[i]);
        }
        if(iMax >= dMax) printf("Case %d. Increasing (%d). Decreasing (%d).\n", i + 1, iMax, dMax);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", i + 1, dMax, iMax);
    }
    return 0;
}