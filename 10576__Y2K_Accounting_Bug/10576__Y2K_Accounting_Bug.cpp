#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, d;
    while(scanf("%d%d", &s, &d) != EOF) {
        int ans = 0;
        for(int i = 0; i <= (1 << 12) - 1; i++) {
            int total = 0, total2 = 0;
            bool broke = false;
            for(int j = 0; j < 12; j++) {
                if((1 << j) & i) {
                    total += s;
                    total2 += s;
                }
                else {
                    total -= d;
                    total2 -= d;
                }
                if(j > 4) {
                    if((1 << (j - 5)) & i)
                        total -= s;
                    else
                        total += d;
                }
                if(j >= 4 && total > 0) {
                    broke = true;
                    break;
                }
            }
            if(!broke && total2 > ans)
                ans = total2;
        }
        if(ans)
            printf("%d\n", ans);
        else
            printf("Deficit\n");
    }

    return 0;
}