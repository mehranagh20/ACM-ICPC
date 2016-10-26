#include <stdio.h>

int main() {
    int bars[20], lenghWeWant, nCases, nBars;
    scanf("%d", &nCases);
    while(nCases--) {
        int possible = 0, i = 0, j = 0;
        scanf("%d%d", &lenghWeWant, &nBars);
        for(; i < nBars; i++)
            scanf("%d", &bars[i]);
        for(i = 0; i < (1 << nBars); i++) {
            int sum = 0;
            for(j = 0; j < nBars; j++) {
                if(i & (1 << j))
                    sum += bars[j];
                if(sum > lenghWeWant)
                    break;
                if(sum == lenghWeWant) {
                    possible = 1;
                    break;
                }
            }
            if(possible)
                break;
        }
        if(possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
}