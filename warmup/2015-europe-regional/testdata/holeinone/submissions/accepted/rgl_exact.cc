#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef __int128 lll;
lll const infinity=((lll) 1)<<((lll) 110);
static lll gcd(lll a,lll b){return b?gcd(b,a%b):a;}

// O(3^N) integer-only solution

struct fraction{
    lll n,d;
    fraction(lll N,lll D){if (D<0) N=-N, D=-D; lll G=gcd(N,D); n=N/G, d=D/G;}
    fraction operator+(fraction const a)const{return fraction(n*a.d+a.n*d,d*a.d);}
    bool operator<(fraction const &a)const{return n/d!=a.n/a.d? n/d<a.n/a.d: n*a.d<a.n*d;}
};

struct vec3{
    union {struct {lll x,y,z;}; lll xyz[3];};
    vec3(lll X=0,lll Y=0,lll Z=1):x(X),y(Y),z(Z){}
    lll       &operator [](int i)      {return xyz[i];}
    lll const &operator [](int i) const{return xyz[i];}
    vec3 operator +(vec3 const &a) const{return {x+a.x,y+a.y,z+a.z};}
    bool operator <(vec3 const &a) const{return x!=a.x? x<a.x: y!=a.y? y<a.y: z<a.z;}
    bool operator ==(vec3 const &a)const{return x==a.x and y==a.y and z==a.z;}
};

lll dot(vec3 const a,vec3 const b){return a.x*b.x+a.y*b.y+a.z*b.z;}

struct mat3{
    private:
        vec3 _row[3];
    public:
        explicit mat3(lll diagonal=1){for (int i=3; i--;) for (int j=3; j--;) _row[i][j]=(i==j?diagonal:0);}
        vec3       &operator [](int r)      {return _row[r];}
        vec3 const &operator [](int r) const{return _row[r];}
        lll       &operator ()(int r,int c)      {return _row[r][c];}
        lll const &operator ()(int r,int c) const{return _row[r][c];}
        vec3 const &row(int r) const{return _row[r];}
        vec3        col(int c) const{return {_row[0][c],_row[1][c],_row[2][c]};}
        mat3 operator *(mat3 const &a) const{mat3 res(0);for (int i=3; i--;) for (int j=3; j--;)res(i,j)=dot(row(i),a.col(j)); return res;}
        vec3 operator *(vec3 const a) const{vec3 res={}; for (int i=3; i--;) res[i]=dot(col(i),a); return res;}
};

mat3 reflector(vec3 a,vec3 b){
    mat3 res(1);
    if (a.x==b.x) return ((res[0][0]=-1), (res[2][0]=a.x*2), res);
    if (a.y==b.y) return ((res[1][1]=-1), (res[2][1]=a.y*2), res);
    assert(false);
}

fraction intersect(vec3 ray,vec3 a,vec3 b){
    if (a.x!=b.x) return intersect({ray.y,-ray.x},{a.y,-a.x},{b.y,-b.x}); // fix case so a -> b is vertical
    if (ray.x<0) return intersect({-ray.x,ray.y},{-a.x,a.y},{-b.x,b.y}); // fix case so ray goes to +x
    if (ray.x==0) return {infinity,1}; // reject parallel lines
    if (a.x<0) return {infinity,1}; // reject negative direction
    long long yat=ray.y*a.x; // compute y-intercept without the division by ray.x (for integer arithmetic)
    if (yat<min(a.y,b.y)*ray.x or max(a.y,b.y)*ray.x<yat) return {infinity,1}; // reject non-intersections
    return fraction(yat*yat,ray.x*ray.x)+fraction(a.x*a.x,1);
}

int verify(vector<pair<vec3,vec3>> walls,vec3 hole,vec3 target){
    fraction last_distance{0,1};
    for (int i=0; i<=walls.size(); i++){
        pair<fraction,int> closest={fraction(target.x*target.x+target.y*target.y,1),-1};
        for (int j=i; j<walls.size(); j++){
            pair<fraction,int> dist={intersect(target,walls[j].first,walls[j].second), j};
            if (dist.first<last_distance)
                continue; // unreachable edge caused by reflection. ignore.
            closest=min(closest, dist);
        }
        last_distance=max(last_distance,closest.first);

        if (closest.second!=i){
            if (closest.second==-1) return target==hole? i: -1;
            swap(walls[i],walls[closest.second]);
        }

        if (i<walls.size()){
            mat3 ref=reflector(walls[i].first,walls[i].second);
            for (int j=i; j<walls.size(); j++){
                walls[j]={ref*walls[j].first,ref*walls[j].second};
            }
            hole=ref*hole;
        }
    }
    return -1;
}

set<int> gen(int x,vector<int> e){
    int mask=1; for (int i=e.size(); i--;) mask*=3;
    set<int> res;
    while (mask--){
        vector<int> a,b;
        for (int i=0,mosk=mask; i<e.size(); i++,mosk/=3)
            if (mosk%3==1) a.push_back(e[i]); else
            if (mosk%3==2) b.push_back(e[i]);
        int y=x;
        for (int i=0; i<e.size(); i++){
            if (i<a.size()) y=2*a[i]-y;
            if (i<b.size()) y=2*b[i]-y;
        }
        res.insert(y);
    }
    return res;
}

int main(){
    int n; cin>>n;
    vec3 target={}; {int x,y; cin>>x>>y; target.x=x,target.y=y;}
    vector<pair<vec3,vec3>> walls(n);
    for (auto &i: walls) {int ax,ay,bx,by; cin>>ax>>ay>>bx>>by; i.first.x=ax,i.first.y=ay,i.second.x=bx,i.second.y=by;}

    vector<int> ex,ey;
    for (int i=0; i<n; i++)
        if (walls[i].first.x==walls[i].second.x) ex.push_back(walls[i].first.x);
        else ey.push_back(walls[i].first.y);

    set<int> px=gen(target.x,ex);
    set<int> py=gen(target.y,ey);

    int res=-1;
    for (int x: px) for (int y: py) res=max(res,verify(walls,target,vec3{x,y}));

    if (res>=0){
        cout<<res<<endl;
    }else{
        cout<<"impossible"<<endl;
    }
}
