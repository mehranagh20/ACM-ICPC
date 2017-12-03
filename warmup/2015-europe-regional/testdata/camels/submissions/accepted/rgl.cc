#include <bits/stdc++.h>
using namespace std;

int const blocksize=128;
int fen[2048][2048];
void up(int x,int y,int z){for (int i=x; !(i&2048); i|=i+1) for (int j=y; !(j&2048); j|=j+1) fen[i][j]+=z;}
int get(int x,int y){int z=0; for (int i=x; ~i; --(i&=i+1)) for (int j=y; j>=0; --(j&=j+1)) z+=fen[i][j]; return z;}

vector<int> y2z(200000,1<<28),z2y=y2z;
struct vec3 {int x,y,z;} p[200000];

int main(){
    ios::sync_with_stdio(false);
    int n; cin>>n;

    for (int i=3; i--;)
        for (int j=n,id; j--;)
            cin>>id, (&p[id-1].x)[i]=j;

    sort(p,p+n, [](vec3 a,vec3 b){
        return a.x^b.x? a.x<b.x: a.y^b.y? a.y<b.y: a.z<b.z;
    });

    long long res=0;
    for (int i=0; i<n; i++){
        res+=get(p[i].y/blocksize,p[i].z/blocksize);
        for (int j=p[i].y-1; (j+1)%blocksize; --j) res+=(y2z[j]<p[i].z);
        for (int j=p[i].z-1; (j+1)%blocksize; --j) res+=(z2y[j]/blocksize<p[i].y/blocksize);
        up(p[i].y/blocksize+1,p[i].z/blocksize+1,1);
        y2z[p[i].y]=p[i].z;
        z2y[p[i].z]=p[i].y;
    }
    cout<<res<<endl;
}
