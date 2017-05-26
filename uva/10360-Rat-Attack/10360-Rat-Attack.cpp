#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> killed;
    vector<int> tmp;
    int t, n, a, b, p, sum, d;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &d, &n);
        tmp.assign(1025 + 2*d, 0);
        killed.assign(1025 + 2*d, tmp);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &a, &b, &p);
            a += d;
            b += d;
            for (int k = a-d; k <= a+d ; ++k) {
                for (int l = b-d; l <= b+d; ++l) {
                    killed[k][l] += p;
                }
            }
        }

        p = 0;
        for (int i = d; i < 1025 + d; ++i) {
            for (int j = d; j < 1025 + d; ++j) {
                if(killed[i][j] > p){
                    p = killed[i][j];
                    a = i - d; b = j - d;
                }
            }
        }

        printf("%d %d %d\n", a, b, p);
    }
    return 0;
}
