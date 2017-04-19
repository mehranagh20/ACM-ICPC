#include <stdio.h>
#include <vector>
#include <algorithm>
#include "string.h"

using namespace std;

int tmpArr[61];
int combHlp[61][61][61];

int main() {
    vector<int> arr;
    vector<pair<int, int>> save(181, make_pair(-1, -1));
    arr.reserve(61);
    for (int i = 0; i <= 20; i++) {
        if (!tmpArr[i]) {
            arr.push_back(i); tmpArr[i] = 1;
        }
        if (!tmpArr[i * 2]) {
            arr.push_back(i * 2); tmpArr[i * 2] = 1;
        }
        if (!tmpArr[i * 3]) {
            arr.push_back(i * 3); tmpArr[i * 3] = 1;
        }
    }
    arr.push_back(50); tmpArr[50] = 1;
    sort(arr.begin(), arr.end());
    int n;
    while (scanf("%d", &n) && n > 0) {
        int permSize = 0, combSize = 0;
        if (n > 180)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n**********************************************************************\n",
                   n);
        else if(save[n].first == -1){
            memset(combHlp, 0, 61 * 61 * 61);
            for (auto &e1 : arr) {
                if(e1 > n)
                    break;
                for (auto & e2 : arr) {
                    if(e1 + e2 > n)
                        break;
                    int thirdNum = n - e1 - e2;
                    if (thirdNum <= 60 && tmpArr[thirdNum]) {
                        permSize++;
                        if(!combHlp[e1][e2][thirdNum])
                        {
                            combHlp[e1][e2][thirdNum] = combHlp[e2][e1][thirdNum] = combHlp[e1][thirdNum][e2] = combHlp[e2][thirdNum][e1] = combHlp[thirdNum][e1][e2] = combHlp[thirdNum][e2][e1] = 1;
                            combSize++;
                        }
                    }
                }
            }
            save[n].first = combSize; save[n].second = permSize;
            if (!permSize)
                printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n**********************************************************************\n",
                       n);
            else {
                printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combSize);
                printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n**********************************************************************\n",
                       n, permSize);
            }
        }
        else {
            if(save[n].first) {
                printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, save[n].first);
                printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n**********************************************************************\n",
                       n, save[n].second);
            }
            else
                printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n**********************************************************************\n",
                       n);

        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
