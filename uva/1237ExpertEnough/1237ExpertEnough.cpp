#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool comFunc(pair<string, pair<int, int>> i, pair<string, pair<int, int>> j) {
    return (i.second.second < j.second.second);
}

int main() {
    int nCases, printSp = 0;
    scanf("%d", &nCases);
    while (nCases--) {
        if(printSp++)
            puts("");
        int d, q, price;
        scanf("%d", &d);
        vector<pair<string, pair<int, int>>> dataBase;
        for (int i = 0; i < d; i++) {
            char tmpStr[30];
            int l, h;
            scanf("%s%d%d", tmpStr, &l, &h);
            dataBase.push_back(make_pair(string(tmpStr), make_pair(l, h)));
            while (getchar() != '\n');
        }
        sort(dataBase.begin(), dataBase.end(), comFunc);
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int low = 0, high = d - 1, index = (d - 1) >> 1;
            scanf("%d", &price);
            while (price > dataBase[index].second.second) {
                low = index;
                index = (low + high) >> 1;
                if (high - index == 1)
                    break;
            }
            while (price > dataBase[index].second.second && index < d)
                index++;
            while (dataBase[index - 1].second.second >= price)
                index--;
            int found = 0, ansIndex;
            for (; index < d; index++) {
                if (price >= dataBase[index].second.first) {
                    found++;
                    if (found > 1)
                        break;
                    ansIndex = index;
                }
            }
            if (found > 1 || !found)
                printf("UNDETERMINED\n");
            else
                printf("%s\n", dataBase[ansIndex].first.c_str());
        }
    }

    return 0;
}