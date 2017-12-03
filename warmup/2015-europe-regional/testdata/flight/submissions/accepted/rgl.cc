#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long double ld;

struct vec3{
    ld x,y,z;
    vec3 operator-(vec3 const &a)const{return {x-a.x,y-a.y,z-a.z};}
    void fix(){ld l=hypotl(hypotl(x,y),z); x/=l,y/=l,z/=l;}
    ld dot(vec3 const &b)const{return x*b.x+y*b.y+z*b.z;}
    vec3 cross(vec3 const &b)const{return {y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x};}
};

vector<vec3> path(bool loop=false){
    int n; cin>>n;
    vector<vec3> res(n);
    for (auto &i: res){
        ld lon,lat; cin>>lat>>lon;
        lon*=M_PI/180.L, lat*=M_PI/180.L;
        i={cos(lat)*sin(lon), sin(lat), cos(lat)*cos(lon)};
    }
    if (loop) res.push_back(res.front());
    return res;
}

vector<vector<vec3>> continents(){
    int n; cin>>n;
    vector<vector<vec3>> res(n);
    for (auto &i: res) i=path(true);
    return res;
}

vector<double> find_intersections(vec3 a, vec3 b, vector<vec3> const &loop){
    static vector<double> res;
    res.clear();

    for (int i=1; i<loop.size(); i++){
        vec3 e=loop[i-1],f=loop[i];

        vec3 u=(e-f).cross(e); u.fix();
        vec3 v=(b-a).cross(b); v.fix();
        vec3 w=u.cross(v); w.fix();
        if (w.dot(a)+w.dot(b)<0) w={-w.x,-w.y,-w.z};

        if (abs(acosl(w.dot(a))+acosl(w.dot(b))-acosl(a.dot(b)))
           +abs(acosl(w.dot(e))+acosl(w.dot(f))-acosl(e.dot(f))) < 1e-9L)
            res.push_back(acosl(w.dot(a)));
    }
    return res;
}

int main(){
    auto c=continents();
    auto p=path();

    vector<ld> when;
    ld len=0.L,frac=0.L;
    for (int i=1; i<p.size(); i++){
        for (auto const &con: c)
            for (auto const f: find_intersections(p[i-1],p[i],con))
                when.push_back(len+f);
        len+=acosl(p[i].dot(p[i-1]));
    }
    sort(when.begin(),when.end());
    for (int i=0; i+2<=when.size(); i+=2) frac+=when[i+1]-when[i];
    frac/=len;

    cout.precision(10);
    cout<<fixed<<len*6370<<" "<<frac*100<<endl;
}
