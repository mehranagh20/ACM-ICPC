#include <stdio.h>


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int arr[1 << 15], i = 0, max = -1;
        for (i; i < (1 << n); i++)
            scanf("%d", &arr[i]);
        i = 0;
        int sum[1 << 15];
        for (i; i < (1 << n); i++)
            sum[i] = 0;
        i = 0;
        for (i; i < (1 << n); i++) {
            int currSum = 0;
            int j = i + 1;
            for (j; j < (1 << n); j++) {
                if (!((j ^ i) & ((j ^ i) - 1))) {
                    currSum += arr[j];
                    sum[j] += arr[i];
                }
            }
            sum[i] += currSum;
            j = 0;
            for (j; j < i; j++) {
                if (!((j ^ i) & ((j ^ i) - 1)) && (sum[i] + sum[j] > max))
                    max = sum[i] + sum[j];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
