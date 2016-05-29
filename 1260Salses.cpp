#include <stdio.h>

int arr[1000];
int maxx[1000];
int num[1000];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, ans = 0, i, max = -1;
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            int tmp, j, tmpNum = 0;
            scanf("%d", &tmp);
            if(tmp > max)
                max = tmp;
            for(j = i - 1; j >= 0; j--) {
                if(tmp >= maxx[j]) {
                    ans += j + 1;
                    tmpNum += num[j];
                    break;
                }
                else if(tmp >= arr[j]) {
                    ans++;
                    tmpNum++;
                }
            }
            num[i] = tmpNum;
            maxx[i] = max;
            arr[i] = tmp;
        }
        printf("%d\n" ,ans);
    }

    return 0;
}