#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int arr[40000];

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        int noCom = 0, pair = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            for(int j = i - 1; j >= 0; j--) {
                pair++;
                if (gcd(arr[i], arr[j]) == 1)
                    noCom++;
            }
        }
        if(!noCom)
            printf("No estimate for this data set.\n");
        else
            printf("%.6f\n", sqrt((6. * pair) / (float)noCom));
    }

    return 0;
}

