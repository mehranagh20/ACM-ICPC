#include <stdio.h>

int main() {
   int nCases, x, y, z;
    scanf("%d", &nCases);
    while(nCases--) {
        int a, b, c, haveSol = 0;
        scanf("%d%d%d", &a, &b, &c);
        for(x = -100; x <= 100; x++) {
            if(x * x > c)
                continue;
            for(y = -100; y <= 100; y++) {
                if(x * x + y * y > c || y == x)
                    continue;
                for(z = -100; z <= 100; z++) {
                    if(z != x && z != y && x * x + y * y + z * z == c && x * y * z == b && x + y + z == a) {
                        haveSol = 1;
                        printf("%d %d %d\n", x, y, z);
                    }
                    if(haveSol)
                        break;
                }
                if(haveSol)
                    break;
            }
            if(haveSol)
                break;
        }
        if(!haveSol)
            printf("No solution.\n");
    }
}