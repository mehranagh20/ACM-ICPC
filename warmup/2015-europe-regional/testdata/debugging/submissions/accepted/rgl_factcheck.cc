#include <algorithm>
#include <cstdio>
long long res[1000001];
int civ(int n,int d){return n/d+!!(n%d);}

int main(){
    int n,t,p; scanf("%d%d%d",&n,&t,&p);
    for (int i=1; i<=n; res[++i]=1ll<<55)
        if (civ(n,civ(n,i))==i)
            for (int j=2; j<=i; j++)
                res[i]=std::min(res[i],res[civ(i,j)]+(j-1ll)*p+t);
    printf("%lld\n",res[n]);
}
