//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int num[1010];

int main() {
    num[0] = 1;
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int ans = 1, tmp, rem, last = 1;
        scanf("%d", &rem);
        for (int i = 1; i < n; i++) {
            scanf("%d", &tmp);
            num[i] = tmp;
            if (rem < tmp)
                ans++;
            else {
                int j = i - 1;
                while(rem >= tmp) {
                    ans--;
                    rem -= num[j--];
                }
                ans++;
            }
            rem += tmp;
        }
        printf("%d\n", ans);
    }

    return 0;
}