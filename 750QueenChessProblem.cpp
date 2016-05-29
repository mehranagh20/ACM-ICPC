#include <stdio.h>
#include <string.h>
#include <bitset>

std::bitset<30> r, rD, lD;
int col[8], repR, repC, solNum = 0;

void printSol() {
    if (!solNum++)
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    printf("%2d     ", solNum);
    for (int i = 0; i < 8; i++)
        printf(" %d", col[i] + 1);
    puts("");
}

void fill(int c) {
    int *tmp = col , a = repR, b = repC;
    if (c == 8)
        return;
    for (int i = 0; i < 8; i++)
        if (!r[i] && !rD[i - c + 7] && !lD[i + c]) {
            r[i] = rD[i - c + 7] = lD[i + c] = 1;
            col[c] = i;
            if (c == 7 && col[repC] == repR)
                printSol();
            fill(c + 1);
            r[i] = rD[i - c + 7] = lD[i + c] = 0;
        }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        solNum = 0;
        r.reset();
        rD = lD = r;
        scanf("%d%d", &repR, &repC);
        repC--; repR--;
        fill(0);

        if (nCase)
            puts("");
    }

    return 0;
}