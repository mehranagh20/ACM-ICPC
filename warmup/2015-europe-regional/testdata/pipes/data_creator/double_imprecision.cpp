#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <numeric>
#include <iomanip>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = 2.0 * acos(0.0);


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)


typedef long long coord;

struct pt{
	coord x,y;
	pt():x(0),y(0){};
	pt(coord _x,coord _y):x(_x),y(_y){};
};

int ccw(pt p0, pt p1, pt p2) {
	coord d1 =(p1.x-p0.x)*(p2.y-p0.y);
	coord d2 =(p2.x-p0.x)*(p1.y-p0.y);
	return (d1-d2>eps)-(d2-d1>eps);
}

int isPointOnSegment(pt p, pt a0, pt a1) {
	if(ccw(a0,a1,p)) return 0;
	coord cx = (p.x-a0.x)*(p.x-a1.x);
	coord cy = (p.y-a0.y)*(p.y-a1.y);
	if(cx > eps || cy > eps) return 0;
	if(cx < -eps || cy < -eps) return 2;
	return 1;
}

bool isSegmentIntersect(pt a0, pt a1, pt b0, pt b1) {
	int c1=ccw(a0,a1,b0);
	int c2=ccw(a0,a1,b1);
	int c3=ccw(b0,b1,a0);
	int c4=ccw(b0,b1,a1);
	if(c1*c2>0 || c3*c4>0) return 0;
	if(!c1 && !c2 && !c3 && !c4) {
		c1=isPointOnSegment(a0,b0,b1);
		c2=isPointOnSegment(a1,b0,b1);
		c3=isPointOnSegment(b0,a0,a1);
		c4=isPointOnSegment(b1,a0,a1);
		if(c1 && c2 && c3 && c4) return 1+(a0.x!=a1.x || a0.y!=a1.y);
		return max(max(c1,c2),max(c3,c4));
	}
	return 1+(!min(c1,c2) || !min(c3,c4));
}





typedef double coord2;

struct pt2{
	coord2 x,y;
	pt2():x(0),y(0){};
	pt2(coord2 _x,coord2 _y):x(_x),y(_y){};

	pt2 operator+(const pt2& p) { return pt2(x+p.x,y+p.y); }
	pt2 operator-(const pt2& p) { return pt2(x-p.x,y-p.y); }
	pt2 operator*(const coord2 f) { return pt2(x*f,y*f); }
	pt2 operator/(const coord2 f) { return pt2(x/f,y/f); }
    bool operator <(const pt2& p) const {
            return x < p.x || (x == p.x && y < p.y);
    }
	coord2 operator*(const pt2& p) { return x*p.x+y*p.y; }
};
double len(pt2 p) { return sqrt(double(p*p)); }
double phi(pt2 p) { return atan2((double)p.y,p.x); }

// ccw test.decides whether three points
// are arranged counterclockwise
// 1=ccw, 0=straight, -1=cw
int ccw2(pt2 p0, pt2 p1, pt2 p2) {
	coord2 d1 =(p1.x-p0.x)*(p2.y-p0.y);
	coord2 d2 =(p2.x-p0.x)*(p1.y-p0.y);
	return (d1-d2>eps)-(d2-d1>eps);
}

// (oo,0)=same, (oo,_)=parallel, (x,y)=point
pt2 lineIntersect(pt2 a0, pt2 a1, pt2 b0, pt2 b1) {
	pt2 d13=a0-b0;
	pt2 d43=b1-b0;
	pt2 d21=a1-a0;
	coord2 un = d43.x*d13.y - d43.y*d13.x;
	coord2 ud = d43.y*d21.x - d43.x*d21.y;
	if(fabs(ud)<eps) return pt2(oo,un);
	return pt2(a0.x + un*d21.x/ud, a0.y + un*d21.y/ud);
}

// 0 = no, 1= on-end-point, 2=strict
int isPointOnSegment(pt2 p, pt2 a0, pt2 a1) {
	if(ccw2(a0,a1,p)) return 0;
	coord2 cx = (p.x-a0.x)*(p.x-a1.x);
	coord2 cy = (p.y-a0.y)*(p.y-a1.y);
	if(cx > eps || cy > eps) return 0;
	if(cx < -eps || cy < -eps) return 2;
	return 1;
}


bool javaTest(pt2 a1,pt2 a2,pt2 b1,pt2 b2){
	return ((ccw2(a1,a2,b1) * ccw2(a1,a2,b2)) <= 0) && ((ccw2(b1,b2,a1) * ccw2(b1,b2,a2)) <= 0);
}


int main(){
	
//	for (ll base = 1L << 27; base <= 1L << 30; base++) /*for(ll add = -3; add <= 3; add++)*/{
		// output on cerr proof that this is a precision sensitive TC
		ll base = 1L << 28;
		ll add = 0;
	
		//pt s1 (-2,-base);
		//pt e1 (1, base);
		//pt s2 (0,base/3+add);
		//pt e2 (base,base);

		pt s1 (-base+1,-base);
		pt e1 (base, base);
		pt s2 (base-1,base-1);
		pt e2 (base-1,2*base);
		//pt s2 (0,0);
		//pt e2 (0,base);
	
	
		pt2 s1_ (s1.x,s1.y);
		pt2 e1_ (e1.x,e1.y);
		pt2 s2_ (s2.x,s2.y);
		pt2 e2_ (e2.x,e2.y);
	
		// print progress
		if (base % (1L << 22) == 0 /*&& add == 0*/) cout << base << endl;
	
		bool rint = isSegmentIntersect(s1,e1,s2,e2);
		bool rdou = javaTest(s1_,e1_,s2_,e2_);
		//if (rint == rdou) continue;
	
		cerr << s2.y << endl;
		cerr << "int " << isSegmentIntersect(s1,e1,s2,e2) << endl;
		cerr << "double " << javaTest(s1_,e1_,s2_,e2_) << endl;

		/*pt2 cut = lineIntersect(s1_,e1_,s2_,e2_);
		cerr << "double cut " << cut.x << " " << cut.y  << endl; 
		cerr << "s2_ " << s2_.x << " " << s2_.y << endl; 
		cerr << "e2_ " << e2_.x << " " << e2_.y << endl; 
		cerr << "double " << isPointOnSegment(cut,s1_,e1_) << " " << isPointOnSegment(cut,s2_,e2_) << endl;*/
//	}
	
	// output the TC
	
	cout << "5 5" << endl;
	cout << s1.x << " " << s1.y << endl;
	cout << e2.x << " " << e2.y << endl;
	cout << e1.y+1 << " " << e1.y+1 << endl;
	cout << -4 << " " << e2.y << endl;
	cout << -5 << " " << 0 << endl;
	cout << "0 " << e1.x << " " << e1.y << endl;
	cout << "1 " << s2.x << " " << s2.y << endl;
	cout << "2 " << -4 << " " << e1.y+1 << endl;
	cout << "3 " << -4 << " " << -1 << endl;
	cout << "3 " << 5 << " " << 1 << endl;
	
	
	
	
}













