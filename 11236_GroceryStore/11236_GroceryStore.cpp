#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int i  = 1; i <= 2000; i++) {
        if(i * i * i * i > 2 * 1000000000)
            break;
        for(int j = i; j <= 2000 - i; j++) {
            int product = i * j;
            if(i * j * j * j > 2 * 1000000000)
                break;
            for (int k = j; k <= 2000 - i - j; k++) {
                product *= k;
                if(i * j * k * k > 2 * 1000000000)
                    break;
                if(i * j * k == 1000000)
                    continue;
                if(((1000000 * (i + j + k)) % (i * j * k - 1000000)))
                    continue;
                int x = (1000000 * (i + j + k)) / (i * j * k - 1000000);
                if(i + j + k + x > 2000 || k > x || i * j * k * x > 2 * 1000000000)
                    continue;
                printf("%.2f %.2f %.2f %.2f\n", i / 100., j / 100., k / 100., x / 100.);
            }
        }
    }

    return 0;
}