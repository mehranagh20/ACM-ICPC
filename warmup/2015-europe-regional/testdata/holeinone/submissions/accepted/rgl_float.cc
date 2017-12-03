#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
float const infinity=1e60L, impossible=-infinity;

// complexity: O(3^N)

struct vec3{
    union {struct {int x,y,z;}; int xyz[3];};
    vec3(int X=0,int Y=0,int Z=1):x(X),y(Y),z(Z){}
    int       &operator [](int i)      {return xyz[i];}
    int const &operator [](int i) const{return xyz[i];}
    vec3 operator +(vec3 const &a) const{return {x+a.x,y+a.y,z+a.z};}
    bool operator <(vec3 const &a) const{return x!=a.x? x<a.x: y!=a.y? y<a.y: z<a.z;}
    bool operator ==(vec3 const &a)const{return x==a.x and y==a.y and z==a.z;}
};

int dot(vec3 const a,vec3 const b){return a.x*b.x+a.y*b.y+a.z*b.z;}

struct mat3{
    private:
        vec3 _row[3];
    public:
        explicit mat3(int diagonal=1){for (int i=3; i--;) for (int j=3; j--;) _row[i][j]=(i==j?diagonal:0);}
        vec3       &operator [](int r)      {return _row[r];}
        vec3 const &operator [](int r) const{return _row[r];}
        int       &operator ()(int r,int c)      {return _row[r][c];}
        int const &operator ()(int r,int c) const{return _row[r][c];}
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

float intersect(vec3 ray,vec3 a,vec3 b){
    if (a.x!=b.x) return intersect({ray.y,-ray.x},{a.y,-a.x},{b.y,-b.x}); // fix case so a -> b is vertical
    if (ray.x<0) return intersect({-ray.x,ray.y},{-a.x,a.y},{-b.x,b.y}); // fix case so ray goes to +x
    if (ray.x==0) return infinity; // reject parallel lines
    if (a.x<0) return infinity; // reject negative direction
    long long yat=ray.y*a.x; // compute y-intercept without the division by ray.x (for integer arithmetic)
    if (yat<min(a.y,b.y)*ray.x or max(a.y,b.y)*ray.x<yat) return infinity; // reject non-intersections
    return hypotl(yat/(float)ray.x,a.x); // looks good; compute exact distance
}

pair<float,int> verify(vector<pair<vec3,vec3>> walls,vec3 hole,vec3 target){
    float last_distance=0.L;
    for (int i=0; i<=walls.size(); i++){
        pair<float,int> closest={hypotl(target.x,target.y),-1};
        for (int j=i; j<walls.size(); j++){
            pair<float,int> dist={intersect(target,walls[j].first,walls[j].second), j};
            if (dist.first+1e-8L<last_distance)
                continue; // unreachable edge caused by reflection. ignore.
            closest=min(closest, dist);
        }
        last_distance=max(last_distance,closest.first);

        if (closest.second!=i){
            if (closest.second==-1) return target==hole? make_pair(closest.first, i): make_pair(impossible, -1);
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
    return {impossible,-1};
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
    vec3 target; cin>>target.x>>target.y;
    vector<pair<vec3,vec3>> walls(n);
    for (auto &i: walls) cin>>i.first.x>>i.first.y>>i.second.x>>i.second.y;

    vector<int> ex,ey;
    for (int i=0; i<n; i++)
        if (walls[i].first.x==walls[i].second.x) ex.push_back(walls[i].first.x);
        else ey.push_back(walls[i].first.y);

    set<int> px=gen(target.x,ex);
    set<int> py=gen(target.y,ey);

    int res=-1;
    for (int x: px) for (int y: py){
        vec3 aim(x,y);
        pair<float,int> result=verify(walls,target,aim);
        if (result.first!=impossible) res=max(res,result.second);
    }

    if (res!=-1){
        cout.precision(14);
        cout<<fixed<<res<<endl;
    }else{
        cout<<"impossible"<<endl;
    }
}
