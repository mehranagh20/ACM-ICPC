#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int p, q, r, s, t, u;

double isSol(double x) {
    return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u );
}

int main() {
    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6) {
        if(isSol(0) < 0 || isSol(1) > EPS) {
            printf("No solution\n");
            continue;
        }
        double low = 0, high = 1, mid;
        for(int i = 0; i < 30; i++) {
            mid = (low + high) / 2;
            if(isSol(mid) > 0) low = mid;
            else high = mid;
        }
        printf("%.4lf\n", mid);

    }

    return 0;
}