#include <stdio.h>

int main() {
    int n, desiredNum;
    while (scanf("%d%d", &n, &desiredNum) && n != 0) {
        if(desiredNum == n * n)
        {
            printf("Line = %d, column = %d.\n", n, n);
            continue;
        }
        int i = n / 2 + 1, j =
                n / 2 + 1, num = 1, tmpI = -1, tmpJ = 1, currSq = 3, addSq = 0, mul = 1;
        while (num != desiredNum) {
            if(currSq - 1 - mul + num <= desiredNum) {
                num += currSq - 1 - mul;
                j += (tmpJ * (currSq - 1 - mul));
            }
            else
            {
                j += (tmpJ * (desiredNum - num));
                num = desiredNum;
            }
            tmpJ *= -1;
            if((currSq - 1 - mul + num <= desiredNum) && desiredNum != num) {
                num += currSq - 1 - mul;
                i += (tmpI * (currSq - 1 - mul));
            }
            else
            {
                i += (tmpI * (desiredNum - num));
                num = desiredNum;
            }
            tmpI *= -1;
            if (num != 5 && num != 3)
                currSq++;
            mul = 0;
        }
        printf("Line = %d, column = %d.\n", j, i);
    }

    return 0;
}
