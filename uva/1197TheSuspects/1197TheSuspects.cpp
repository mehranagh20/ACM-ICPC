#include <stdio.h>

int set[30010];
int gNum[30010];

void uFDS(int n){
    int i = 0;
    for(; i < n; i++){
        set[i] = i;
        gNum[i] = 1;
    }
}

int findSet(int i){
    if(set[i] == i)
        return i;
    else
        return findSet(set[i]);
}

void merge(int i, int j){
    int setI = findSet(i), setJ = findSet(j);
    if(setI != setJ){
        if(setI < setJ){
            set[setJ] = setI;
            gNum[setI] += gNum[setJ];
        }
        else{
            set[setI] = setJ;
            gNum[setJ] += gNum[setI];
        }
    }
}

int main(){
    int nS, nG;
    while(scanf("%d%d", &nS, &nG) && (nS || nG)){
        if(nS == 0)
            printf("0\n");
        else {
            uFDS(nS);
            while(nG--){
                int k, tmp1, tmp2;
                scanf("%d", &k);
                k--;
                scanf("%d", &tmp1);
                while(k--){
                    scanf("%d", &tmp2);
                    merge(tmp1, tmp2);
                }
            }
            printf("%d\n", gNum[0]);
        }
    }
    return 0;
}