#include <stdio.h>

int calG(int arr[][3]) {
    int tmp[3][3];
    int isAllZ = 0, o = 0;
    while(isAllZ == 0) {
        o++;
        isAllZ = 1;
        int i = 0;
        for (; i < 3; i++) {
            int j = 0;
            for (; j < 3; j++) {
                int sum = 0;
                if (j == 0) {
                    if (i == 0) {
                        sum += arr[0][1] + arr[1][0];
                    }
                    else if (i == 2) {
                        sum += arr[2][1] + arr[1][0];
                    }
                    else {
                        sum += arr[1][1] + arr[0][0] + arr[2][0];
                    }
                }
                else if (j == 2) {
                    if (i == 0) {
                        sum += arr[0][1] + arr[1][2];
                    }
                    else if (i == 2) {
                        sum += arr[2][1] + arr[1][2];
                    }
                    else {
                        sum += arr[1][1] + arr[0][2] + arr[2][2];
                    }
                }
                else {
                    if (i == 0) {
                        sum += arr[0][0] + arr[0][2] + arr[1][1];
                    }
                    else if (i == 2) {
                        sum += arr[2][0] + arr[2][2] + arr[1][1];
                    }
                    else {
                        sum += arr[0][1] + arr[1][0] + arr[1][2] + arr[2][1];
                    }
                }
                if(sum % 2)
                {
                    isAllZ = 0;
                    tmp[i][j] = 1;
                }
                else
                    tmp[i][j] = 0;
            }
        }
        int d = 0;
        for (; d < 3; d++)
        {
            int j = 0;
            for (; j < 3; j++)
                arr[d][j] = tmp[d][j];
        }
    }
    return o;
}

int main() {
    int arr[3][3], n;
    scanf("%d", &n);
    while (getchar() != '\n');
    while (getchar() != '\n');
    while (n--) {
        int hlp = 1;
        int i = 0;
        for (; i < 3; i++) {
            int j = 0;
            for (; j < 3; j++) {
                char c = getchar();
                if (c == '0')
                    arr[i][j] = 0;
                else {
                    arr[i][j] = 1;
                    hlp = 0;
                }
            }
            while (getchar() != '\n');
        }
        if(hlp)
        {
            printf("-1\n");
            while(getchar() != '\n');
            continue;
        }
        printf("%d\n", calG(arr) - 1);
        while(getchar() != '\n');
    }

    return 0;
}
