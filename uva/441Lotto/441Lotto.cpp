#include <stdio.h>

int main() {
    int k, i, j, q, y, u, t, printSpace = 0;
    while(scanf("%d", &k) && k) {
        if(printSpace++)
            puts("");
        int arr[13];
        for(i = 0; i < k; i++)
            scanf("%d", &arr[i]);
        for(i = 0; i < k - 5; i++)
            for(j = i + 1; j < k - 4; j++)
                for(q = j + 1; q < k - 3; q++)
                    for(y = q + 1; y < k - 2; y++)
                        for(u = y + 1; u < k - 1; u++)
                            for(t = u + 1; t < k; t++)
                                printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[q], arr[y], arr[u], arr[t]);

    }

    return 0;
}