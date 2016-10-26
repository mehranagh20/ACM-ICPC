#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        map<int, vector<int>> occurences;
        int place = 1;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (occurences.find(tmp) == occurences.end()) {
                vector<int> tmpVec;
                tmpVec.push_back(place++);
                occurences.insert(make_pair(tmp, tmpVec));
            }
            else
                occurences[tmp].push_back(place++);
        }
        while (m--) {
            int tmp1, tmp2;
            scanf("%d%d", &tmp1, &tmp2);
            if (occurences[tmp2].size() < tmp1)
                printf("0\n");
            else
                printf("%d\n", occurences[tmp2][tmp1 - 1]);
        }
    }

    return 0;
}
