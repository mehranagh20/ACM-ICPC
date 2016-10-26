#include <stdio.h>
#include <bitset>

int main() {
    int n, pNewL = 0;
    std::bitset<10> tmpBitSet;
    tmpBitSet.set();
    while(scanf("%d", &n) && n) {
        if(pNewL++)
            puts("");
        int nSol = 0, i;
        for(i = 1234; i <= 98765; i++) {
            int tmp = i * n, sNum = i, isOkTillNow = 1;
            int fNum = tmp;
            std::bitset<10> isAllResereved(0);
            if(i < 10000)
                isAllResereved[0] = 1;
            while(sNum) {
                if(isAllResereved[sNum % 10]) {
                    isOkTillNow = 0;
                    break;
                }
                isAllResereved[sNum % 10] = 1;
                sNum /= 10;
            }
            while(tmp && isOkTillNow) {
                if(isAllResereved[tmp % 10]) {
                    isOkTillNow = 0;
                    break;
                }
                isAllResereved[tmp % 10] = 1;
                tmp /= 10;
            }
            if(isOkTillNow && (tmpBitSet == isAllResereved)) {
                nSol++;
                printf("%.5d / %.5d = %d\n", fNum, i, n);
            }

        }
        if(!nSol)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}