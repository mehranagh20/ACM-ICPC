#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;


int main() {
    int dis[25][25];
    for(int i = 0; i < 25; i++)
        for(int j = i; j < 25; j++) {

            dis[i][j] = dis[j][i] = (abs(((i + 5) % 5) - ((j + 5) % 5)) + (j / 5 - i / 5));
        }
    int n;
    scanf("%d", &n);
    while(n--) {
        int tmp;
        vector<pair<int, int>> placeOfQ;
        scanf("%d", &tmp);
        placeOfQ.reserve(tmp);
        for(int i = 0; i < tmp; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            placeOfQ.push_back(make_pair(a * 5 + b, c));
        }
        int ans[5], sum = 1000000, tmpInt = 1;
        int i = 0, j, d, k, r;
        for(i = 0; i < 21 && tmpInt; i++) {
            for (j = i + 1; j < 22 && tmpInt; j++)
                for (d = j + 1; d < 23 && tmpInt; d++)
                    for (k = d + 1; k < 24 && tmpInt; k++)
                        for (r = k + 1; r < 25 && tmpInt; r++) {
                            int curSum = 0;
                            for (int q = 0; q < tmp; q++)
                                curSum += min(dis[placeOfQ[q].first][i],
                                              min(dis[placeOfQ[q].first][j],
                                                  min(dis[placeOfQ[q].first][d],
                                                      min(dis[placeOfQ[q].first][r],
                                                          dis[placeOfQ[q].first][k])))) * placeOfQ[q].second;

                            if (curSum < sum) {
                                if(sum == 0)
                                    tmpInt = 0;
                                sum = curSum;
                                ans[0] = i;
                                ans[1] = j;
                                ans[2] = d;
                                ans[3] = k;
                                ans[4] = r;
                            }
                        }
        }
        printf("%d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
    }
    return 0;
}