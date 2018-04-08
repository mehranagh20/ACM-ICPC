#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int f, r, tmp;
    while(scanf("%d", &f) && f) {
        scanf("%d", &r);
        vector<int> front(f), rear(r);
        vector<double> ratios(f * r);
        for(int i = 0; i < f; i++)
            scanf("%d", &front[i]);
        for(int i = 0; i < r; i++)
            scanf("%d", &rear[i]);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < f; j++)
                ratios[i * f + j] = (double)rear[i] / front[j];
        sort(ratios.begin(), ratios.end());
        double max = 0;
        for(int i = 0; i < f * r - 1; i++)
            if(ratios[i + 1] / ratios[i] > max)
                max = ratios[i + 1] / ratios[i];
        printf("%.2f\n", max);
    }

    return 0;
}