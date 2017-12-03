#include <stdio.h>

main(){
    int n; scanf("%d",&n);
    while (n--){
        int x,a=0,b=0; scanf("%d",&x);
        for (int j=512; j>>=1;)
            a^=((!((x|  0)&(j)))!=!(a&(j<<1)))?j:0,
            b^=((!((x|256)&(j)))!=!(b&(j<<1)))?j:0;
        printf("%d%c",(a&1?b:a)/2,n?' ':'\n');
    }
}
