#include <stdio.h>
#include "stdlib.h"
#include <vector>

using namespace std;

int main() {
    int m;
    char c;
    while (scanf("%d", &m) != EOF) {
        while (getchar() != '\n');
        vector<pair<int, int>> onesIndeces;
        vector<pair<int, int>> threesIndecex;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                c = getchar();
                if (c == '1')
                    onesIndeces.push_back(make_pair(i, j));
                else if (c == '3')
                    threesIndecex.push_back(make_pair(i, j));
            }
            if (i != m - 1)
                while (getchar() != '\n');
        }
        int ans = -1;
        for (auto &e : onesIndeces) {
            int tmp = 1000;
            for (auto &e2 : threesIndecex)
                if (abs(e.first - e2.first) + abs(e.second - e2.second) < tmp)
                    tmp = abs(e.first - e2.first) + abs(e.second - e2.second);
            if (ans < tmp)
                ans = tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
