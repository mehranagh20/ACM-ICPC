#include <stdio.h>
#include <vector>

using namespace std;

int findSet(int i, vector<int> &set){
    return (set[i] == i ? i : findSet(set[i], set));
}

void merge(int i, int j, vector<int> &set, int &num){
    int setI = findSet(i, set), setJ = findSet(j, set);
    set[i] = setI; set[j] = set[j];
    if(setI != setJ){
        num--;
        setI < setJ ? set[setJ] = setI : set[setI] = setJ;
    }
}

int main(){
    int nS, nG, ncase = 1;
    while(scanf("%d%d", &nS, &nG) && (nS || nG)) {
        vector<int> set(nS + 1);
        int nReligions = nS;
        while(nG--){
            int tmp1, tmp2;
            scanf("%d%d", &tmp1, &tmp2);
            if(!set[tmp1])
                set[tmp1] = tmp1;
            if(!set[tmp2])
                set[tmp2] = tmp2;
            merge(tmp1, tmp2, set, nReligions);
        }
        printf("Case %d: %d\n", ncase++, nReligions);
    }
    return 0;
}