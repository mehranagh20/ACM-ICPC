#include <stdio.h>

int main() {
    int coef[30];
    int nCases;
    scanf("%d", &nCases);
    while (nCases--) {
		int mPow, d, k, tmp, i;
        unsigned long long int ans = 0;
        scanf("%d", &mPow);
        for(i = 0; i < mPow + 1; i++)
            scanf("%d", &coef[i]);
        scanf("%d%d", &d, &k);
        tmp = d; i = 1;
        while(1) {
            if(k <= d)
                break;
            d += tmp * (++i);
        }
        unsigned long long int powTmp = 1, j = 0;
        for(; j < mPow + 1; j++) {
            ans += powTmp * coef[j];
            powTmp *= i;
        }
        printf("%llu\n", ans);
    }

    return 0;
}