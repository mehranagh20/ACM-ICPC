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
#include <cassert>

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


typedef long double coord;

struct pt{
	coord x,y;
	pt():x(0),y(0){};
	pt(coord _x,coord _y):x(_x),y(_y){};

	pt operator+(const pt& p) { return pt(x+p.x,y+p.y); }
	bool operator==(const pt& p) { return (x == p.x) && (y == p.y); }
	pt operator-(const pt& p) { return pt(x-p.x,y-p.y); }
	pt operator*(const coord f) { return pt(x*f,y*f); }
	pt operator/(const coord f) { return pt(x/f,y/f); }
    bool operator <(const pt& p) const {
            return x < p.x || (x == p.x && y < p.y);
    }
	coord operator*(const pt& p) { return x*p.x+y*p.y; }
};
double len(pt p) { return sqrt(double(p*p)); }
double phi(pt p) { return atan2((double)p.y,p.x); }

// ccw test.decides whether three points
// are arranged counterclockwise
// 1=ccw, 0=straight, -1=cw
int ccw(pt p0, pt p1, pt p2) {
	coord d1 =(p1.x-p0.x)*(p2.y-p0.y);
	coord d2 =(p2.x-p0.x)*(p1.y-p0.y);
	return (d1-d2>eps)-(d2-d1>eps);
}

// (oo,0)=same, (oo,_)=parallel, (x,y)=point
pt lineIntersect(pt a0, pt a1, pt b0, pt b1) {
	pt d13=a0-b0;
	pt d43=b1-b0;
	pt d21=a1-a0;
	coord un = d43.x*d13.y - d43.y*d13.x;
	coord ud = d43.y*d21.x - d43.x*d21.y;
	if(abs(ud)<eps) return pt(oo,un);
	return pt(a0.x + un*d21.x/ud, a0.y + un*d21.y/ud);
}

// 0 = no, 1= on-end-point, 2=strict
int isPointOnSegment(pt p, pt a0, pt a1) {
	if(ccw(a0,a1,p)) return 0;
	coord cx = (p.x-a0.x)*(p.x-a1.x);
	coord cy = (p.y-a0.y)*(p.y-a1.y);
	if(cx > eps || cy > eps) return 0;
	if(cx < -eps || cy < -eps) return 2;
	return 1;
}


map<int,pt> wells;

pt pipeEnds[1000];
int toWell[1000];



int dx[] = {0,0,0,1,-1,1,-1,1,-1};
int dy[] = {0,1,-1,0,0,1,1,-1,-1};

// the check will be whether two intersections are within 1/precision_factor of each other. If so they will be treated as identical
int const precision_factor = 10000;


int main(){
	int W,P;
	cin >> W >> P;

	// read the wells
	FOR(i,0,W){
		pt x; cin >> x.x >> x.y;
		wells[i] = x;
		FOR(j,0,i) {
		  if(wells[i].x == wells[j].x && wells[i].y == wells[j].y) {
		    return 0;
		  }
		}
	}
	
	// read the pipes
	FOR (i,0,P) {
		cin >> toWell[i] >> pipeEnds[i].x >> pipeEnds[i].y;
		toWell[i]--;
		if (pipeEnds[i].x == wells[toWell[i]].x  && pipeEnds[i].y == wells[toWell[i]].y) return 0;
	}
	
	
	set<pii> intersects;
	
	cout << "STAGE 1: ";
	// pipe ends should be different from their well
	FOR(i,0,P) if (pipeEnds[i] == wells[toWell[i]]) return 0;
	cout << "complete" << endl;
	
	cout << "STAGE 2: ";
	// check whether there is only the source well on every pipe
	FOR(i,0,P) FOR(j,0,W) if (j != toWell[i]) if (isPointOnSegment(wells[j],pipeEnds[i],wells[toWell[i]])) return 0;
	cout << "complete" << endl;
	
	cout << "STAGE 3: ";
	// cuts of pipes i and j
	FOR(i,0,P) FOR(j,0,i){
		if (toWell[i] == toWell[j]) {
			// Pipes originating at same well: check that not
			// overlapping (in which case one endpoint would be on the
			// other segment)
			assert(!isPointOnSegment(pipeEnds[i], wells[toWell[j]], pipeEnds[j]));
			assert(!isPointOnSegment(pipeEnds[j], wells[toWell[i]], pipeEnds[i]));
			continue;
		}
		// compute the intersection of the lines going through the wells and the respective pipe end
		pt ints = lineIntersect(pipeEnds[i],wells[toWell[i]],pipeEnds[j],wells[toWell[j]]);
		
		// if the lines are identical, i.e.
		if (ints.x == oo && ints.y == 0) {
			// this is illegal if one pipe ends strictly with the other as they would share more than a single point
			if (isPointOnSegment(pipeEnds[j],pipeEnds[i],wells[toWell[i]]) == 2) return 0;
			// the same of they only touch, but this point is a well (the wells are not identical)
			if (isPointOnSegment(wells[toWell[j]],pipeEnds[i],wells[toWell[i]]) >= 1) return 0;
			continue;
		}
		// pipes are strictly parallel, so ok.
		if (ints.x == oo) continue;

		// check whether the line segments actually intersect (ints is only computed for lines)
		if (isPointOnSegment(ints,pipeEnds[i],wells[toWell[i]]) && isPointOnSegment(ints,pipeEnds[j],wells[toWell[j]])){
			// test whether there is another intersection in the vicinity (currently 10^-4). If so this TC will be judged as bad
			pii roughIntersect (int(ints.x*precision_factor),int(ints.y*precision_factor));
			FOR(d,0,9){
				pii rI2 (roughIntersect.first + dx[d], roughIntersect.second + dy[d]);
				if (intersects.count(rI2)) { cout << "Too narrow intersection " << endl; return 0;}
				intersects.insert(rI2);
			}
		}
	}
	cout << "complete" << endl;



	//assert(false);
	return 42;
}



















