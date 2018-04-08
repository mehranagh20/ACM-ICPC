//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n, l, r;
    while (scanf("%u%u%u", &n, &l, &r) == 3) {
        unsigned int ans = 0, tmp = (1 << 31) - 1;
        tmp |= (1 << 31);
        for (int i = 31; i >= 0; i--) {
            if (((1 << i) & n) == 0 && (ans | (1 << i)) <= r)
                ans |= (1 << i);
            tmp ^= (1 << i);
            if(tmp + ans < l)
                ans |= (1 << i);
        }
        printf("%u\n", ans);
    }

    return 0;
}