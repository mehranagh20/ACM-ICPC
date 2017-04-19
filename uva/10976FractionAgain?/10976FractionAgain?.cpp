#include <stdio.h>

int main() {
    int k, arr[1000][2];
    while(scanf("%d", &k) != EOF) {
        int ans = 0, i = 1;
        for(; i <= k; i++) {
            if(!(k * (k + i) % i)) {
                arr[ans][0] = k + i;
                arr[ans++][1] = (k * (k + i) / i);
            }
        }
        printf("%d\n", ans);
        for(i = 0; i < ans; i++)
            printf("1/%d = 1/%d + 1/%d\n", k, arr[i][1], arr[i][0]);
    }

    return 0;
}