//in the name of god...
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2*1e4+10;
int headD[MAX], heights[MAX];

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) && (n || m)) {
        for(int i = 0; i < n; i++) scanf("%d", &headD[i]);
        for(int i = 0; i < m; i++) scanf("%d", &heights[i]);
        sort(headD, headD + n); sort(heights, heights + m);
        int ans = 0, j = 0;
        for(int i = 0; i < n; i++) {
            int found = 0;
            for(; j < m; j++) {
                if(heights[j] >= headD[i]) {
                    found = 1; ans += heights[j];
                    j++;
                    break;
                }
            }
            if(!found) {ans = -1; break;}
        }
        if(ans == -1) printf("Loowater is doomed!\n");
        else printf("%d\n", ans);
    }

    return 0;
}