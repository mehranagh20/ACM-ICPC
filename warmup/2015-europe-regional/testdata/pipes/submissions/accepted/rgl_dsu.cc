#include <cstdio>

int q[2001],r[2001];
int rt(int a){return q[a]?q[a]=rt(q[a]):a;}
void mrg(int a,int b){a=rt(a),b=rt(b);if(a!=b) r[a]<r[b]?q[a]=b,++r[b]:q[b]=a,++r[a];}

struct vec2{long long x,y;bool operator!=(vec2 a)const{return (x^a.x)|(y^a.y);}} sp[2000],tp[1000];
vec2 sub(vec2 a,vec2 b){return {a.x-b.x,a.y-b.y};}
long long cz(vec2 a,vec2 b){return a.y*b.x-a.x*b.y;}

bool collide(int a,int b){
  return sp[a]!=sp[b] and sp[a]!=tp[b] and sp[b]!=tp[a]
    and cz(sub(sp[b],sp[a]),sub(tp[a],sp[a]))*(__int128)cz(sub(tp[b],sp[a]),sub(tp[a],sp[a]))<=0
    and cz(sub(sp[a],sp[b]),sub(tp[b],sp[b]))*(__int128)cz(sub(tp[a],sp[b]),sub(tp[b],sp[b]))<=0;
}

int main(){
  int w,p; scanf("%d %d",&w,&p);
  for (int i=0; i<w; i++) scanf("%lld %lld",&sp[i+p].x,&sp[i+p].y);
  for (int i=p; i--;) scanf("%lld %lld %lld",&sp[i].x,&tp[i].x,&tp[i].y),sp[i].x--, sp[i]=sp[sp[i].x+p];

  for (int i=p; i--;)
    for (int j=p; j--;)
      if (i!=j and collide(i,j))
        mrg(i*2+1,j*2+2);

    for (int i=p; i--;)
      if (rt(i*2+1)==rt(i*2+2))
        return not puts("impossible");
    return not puts("possible");
}
