#include <stdio.h>

int set[10000];
int moneyOwe[10000];

int findSet(int i) {
    if (set[i] == i)
        return i;
    else
        return findSet(set[i]);
}

void merge(int i, int j) {
    int setI = findSet(i), setJ = findSet(j);
    if (setI != setJ) {
        if (setI < setJ) {
            set[setJ] = setI;
            moneyOwe[setI] += moneyOwe[setJ];
        }
        else {
            set[setI] = setJ;
            moneyOwe[setJ] += moneyOwe[setI];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int nF, nR;
        scanf("%d%d", &nF, &nR);
        int i = 0;
        for (; i < nF; i++) {
            scanf("%d", &moneyOwe[i]);
            set[i] = i;
        }
        while (nR--) {
            int f1, f2;
            scanf("%d%d", &f1, &f2);
            merge(f1, f2);
        }
        int *s = set;
        int *m = moneyOwe;
        int isPos = 1;
        for (i = 0; i < nF; i++) {
            if(set[i] == i && moneyOwe[i]) {
                isPos = 0;
                break;
            }
        }
        if(isPos)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }

    return 0;
}