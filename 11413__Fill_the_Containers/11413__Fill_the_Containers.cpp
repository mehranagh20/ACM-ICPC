#include <bits/stdc++.h>

using namespace std;

int n, m, ves[10100];

int isOk(int cap) {
    int storages = 1, tillNow = 0;
    for(int i = 0; i < n; i++) {
        if(tillNow + ves[i] > cap) {
            storages++; tillNow = 0;
        }
        tillNow += ves[i];
        if(storages > m || ves[i] > cap)
            return 0;
    }
    return (storages <= m);
}

int main(int argc, char *argv[]) {
    while(scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &ves[i]);
        int low = 0, high = 1e9, mid;
        while (high - low > 1) {
            mid = (low + high) / 2;
            if (isOk(mid)) high = mid;
            else low = mid;
        }
        if(mid) printf("%d\n", high);
        else printf("1\n");

    }
    return 0;
}