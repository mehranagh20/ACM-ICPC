#include <bits/stdc++.h>

using namespace std;

int nSpaces;
vector<pair<int, int>> dominoes;
int usedBef[20];

bool solution(int pre, int tillNow) {
    vector<pair<int, int>> &v = dominoes;
    if(tillNow == nSpaces) {
        if(dominoes[pre].second == dominoes[dominoes.size() - 1].first)
            return true;
        return false;
    }
    for(int i = 1; i < dominoes.size() - 1; i++) {
        if(!usedBef[i] && dominoes[pre].second == dominoes[i].first) {
            usedBef[i] = true;
            if (solution(i, tillNow + 1))
                return true;
            usedBef[i] = false;
        }
        else if(!usedBef[i] && dominoes[pre].second == dominoes[i].second) {
            int tmp = dominoes[i].first;
            dominoes[i].first = dominoes[i].second;
            dominoes[i].second = tmp;
            usedBef[i] = true;
            if (solution(i, tillNow + 1))
                return true;
            usedBef[i] = false;
        }
    }
    return false;
}

int main() {
    while(scanf("%d", &nSpaces) && nSpaces) {
        memset(usedBef, 0, 20 * sizeof(int));
        int m;
        scanf("%d", &m);
        dominoes.resize(m + 2);
        int a, b;
        scanf("%d%d", &a, &b);
        dominoes[0] = make_pair(a, b);
        scanf("%d%d", &a, &b);
        dominoes[m + 1] = make_pair(a, b);
        for(int i = 1; i <= m ; i++) {
            scanf("%d%d", &a, &b);
            dominoes[i] = make_pair(a, b);
        }
        if(solution(0, 0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}