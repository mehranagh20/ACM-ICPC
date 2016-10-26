#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int nCon, years = 0;
        scanf("%d\n", &nCon);
        map<char, pair<vector<int>, bool>> awaked;
        char c;
        vector<int> tmp;
        while ((c = getchar()) != '\n') {
            if (isalpha(c))
                awaked.insert(make_pair(c, make_pair(tmp, true)));
        }
        for (int i = 0; i < nCon; i++) {
            char a, b;
            scanf("%c%c", &a, &b);
            if (awaked.find(a) == awaked.end()) {
                tmp.push_back(b);
                awaked.insert(make_pair(a, make_pair(tmp, false)));
                tmp.clear();
            }
            else
                awaked[a].first.push_back(b);
            if (awaked.find(b) == awaked.end()) {
                tmp.push_back(a);
                awaked.insert(make_pair(b, make_pair(tmp, false)));
                tmp.clear();
            }
            else
                awaked[b].first.push_back(a);
            while (getchar() != '\n');
        }
        bool possible = true;
        if (nCon + awaked.size() < n)
            possible = false;
        else
            while (true) {
                bool allAwake = true;
                vector<char> tmp;
                for (auto &e : awaked) {
                    if (e.second.second)
                        continue;
                    allAwake = false;
                    if (e.second.first.size() < 3) {
                        possible = false;
                        break;
                    }
                    int num = 0;
                    for (int i = 0; i < e.second.first.size(); i++)
                        if (awaked[e.second.first[i]].second)
                            num++;
                    if (num >= 3)
                        tmp.push_back(e.first);
                }
                if (allAwake || !possible)
                    break;
                if(tmp.empty())
                {
                    possible = false;
                    break;
                }
                for (auto &e : tmp)
                    awaked[e].second = true;
                years++;
            }
        !possible ? printf("THIS BRAIN NEVER WAKES UP\n") : printf("WAKE UP IN, %d, YEARS\n", years);
    }

    return 0;
}
