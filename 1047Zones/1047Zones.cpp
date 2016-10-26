#include <bits/stdc++.h>

using namespace std;

int main() {
    int towrs[20], conss[10], caseNum = 1;
    int n, m, c;
    while(scanf("%d%d", &n, &m) && (n || m) ) {
        int max = 0, ans;
        for (int i = n - 1; i >= 0; i--)
            scanf("%d", &towrs[i]);
        int to = (1 << m) - 1;
        int from = to << (n - m);
        scanf("%d", &c);
        vector<pair<int, int>> constrains(c);
        for (int i = 0; i < c; i++) {
            int nn, num = 0;
            scanf("%d", &nn);
            for (int j = 0; j < nn; j++) {
                int tmp;
                scanf("%d", &tmp);
                num |= (1 << (n - tmp));
            }
            constrains[i].first = num;
            constrains[i].second = nn;
            int numberOfOverload;
            scanf("%d", &numberOfOverload);
            conss[i] = numberOfOverload;
        }
        for (; from >= to; from--) {
            int numberConsidered = 0, total = 0;
            for (int i = 0; i < n; i++)
                if ((1 << i) & from) {
                    numberConsidered++;
                    total += towrs[i];
                }
            if (numberConsidered == m) {
                for (int i = 0; i < c; i++) {
                    int num = constrains[i].first & from;
                    int nn = 0;
                    for(int j = 0; j < n; j++)
                        if((1 << j) & num)
                            nn++;
                    if(num)
                    total -= (nn - 1) * conss[i];
                }
                if (total > max) {
                    max = total;
                    ans = from;
                }
                else if (total == max && from > ans) {
                    max = total;
                    ans = from;
                }
            }
        }
         printf("Case Number  %d\n", caseNum++);
        printf("Number of Customers: %d\nLocations recommended:", max);
        for (int i = n - 1; i >= 0; i--) {
            if ((1 << i) & ans)
                printf(" %d", n - i);
        }
        puts("\n");
    }


    return 0;
}