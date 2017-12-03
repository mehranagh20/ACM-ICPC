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


typedef long double coord;

struct pt{
	coord x,y;
	pt():x(0),y(0){};
	pt(coord _x,coord _y):x(_x),y(_y){};

	pt operator+(const pt& p) { return pt(x+p.x,y+p.y); }
	pt operator-(const pt& p) { return pt(x-p.x,y-p.y); }
	pt operator*(const coord f) { return pt(x*f,y*f); }
	pt operator/(const coord f) { return pt(x/f,y/f); }
	bool operator==(const pt& p) { return (x == p.x) && (y == p.y); }
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


vi adj[2000][2];
int ccomp, comp[2000];
vi st;

void dfs(int n, int c, int dir) {
	if (comp[n] != -1)
		return;
	comp[n] = c;
	FOR(i,0,sz(adj[n][dir]))
		dfs(adj[n][dir][i], c, dir);
	if (!dir)
		st.push_back(n);
}

void kosa(int n) {
	memset(comp, -1, sizeof(comp));
	st.clear();

	FOR(i,0,n)
		dfs(i, 0, 0);

	reverse(all(st));
	memset(comp, -1, sizeof(comp));

	ccomp = 0;

	FOR(i,0,sz(st))
		if (comp[st[i]] == -1)
			dfs(st[i], ccomp++, 1);
}

int notC(int x) {return x^1;}

void clause(int x){
	adj[notC(x)][0].push_back(x);
	adj[x][1].push_back(notC(x));
}

void clause(int x, int y){
	adj[notC(x)][0].push_back(y);
	adj[y][1].push_back(notC(x));
	
	adj[notC(y)][0].push_back(x);
	adj[x][1].push_back(notC(y));
}


map<int,pt> wells;

pt pipeEnds[1000];
int toWell[1000];


int main(){
	int W,P;
	cin >> W >> P;
	FOR(p,0,2*P) adj[p][0].clear(), adj[p][1].clear();
	// read the wells
	FOR(i,0,W){
		pt x; cin >> x.x >> x.y;
		wells[i] = x;
	}
	// read the pipes
	FOR (i,0,P) cin >> toWell[i] >> pipeEnds[i].x >> pipeEnds[i].y, toWell[i]--;
	
	// cuts
	FOR(i,0,P) FOR(j,0,i)
		if (toWell[i] != toWell[j]){		
			pt ints = lineIntersect(pipeEnds[i],wells[toWell[i]],pipeEnds[j],wells[toWell[j]]);
			if (ints.x == oo && ints.y == 0) {
				if (isPointOnSegment(pipeEnds[j],pipeEnds[i],wells[toWell[i]]) == 1) clause(2*i,2*j),clause(notC(2*i),notC(2*j));
				continue;
			}
			if (ints.x == oo) continue;
		
			if (isPointOnSegment(ints,pipeEnds[i],wells[toWell[i]]) && isPointOnSegment(ints,pipeEnds[j],wells[toWell[j]]))
				clause(2*i,2*j),clause(notC(2*i),notC(2*j));
		}
	kosa(2*P);
	
	bool fail = false;
	FOR(i,0,P) fail |= comp[2 * i] == comp[2 * i + 1];
	if (!fail) cout << "possible" << endl;
	else cout << "impossible" << endl;
}
