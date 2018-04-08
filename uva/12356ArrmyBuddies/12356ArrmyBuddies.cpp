#include <stdio.h>

int main() {
    int nSol, nRep;
    int left[100001], right[100001];
    left[0] = 0;
    while (scanf("%d%d", &nSol, &nRep) && nSol != 0) {
        right[nSol + 1] = nSol + 1;
        for (int i = 1; i <= nSol; i++) {
            right[i] = i + 1;
            left[i] = i - 1;
        }
        while(nRep--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if(left[l])
                printf("%d ", left[l]);
            else
                printf("* ");
            if(right[r] != nSol + 1)
                printf("%d\n", right[r]);
            else
                printf("*\n");
            left[right[r]] = left[l];
            right[left[l]] = right[r];
        }
        printf("-\n");
    }

    return 0;
}
