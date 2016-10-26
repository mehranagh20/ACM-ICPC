#include <stdio.h>

int hasConf(int i, int j, short int *cal){
    int k = i;
    for(; k < j; k++){
        if(cal[k])
            return 1;
        cal[k] = 1;
    }
    return 0;
}

int main(){
    int norm, rep;
    while(scanf("%d%d", &norm, &rep) && (norm || rep)){
        short int cal[1000010] = {0};
        int conf = 0;
        int k = 0;
        for(; k < norm; k++) {
            int i, j;
            scanf("%d%d", &i, &j);
            if(!conf && hasConf(i, j, cal))
                conf = 1;
        }
        for(k = 0; k < rep; k++){
            int i, j, repT;
            scanf("%d%d%d", &i, &j, &repT);
            while(i <= 1000000 && !conf){
                if(hasConf(i, j, cal))
                    conf = 1;
                i += repT;
                j += repT;
                if(j > 1000000)
                    j = 1000000;
            }
        }
        if(conf)
            printf("CONFLICT\n");
        else
            printf("NO CONFLICT\n");
    }
}