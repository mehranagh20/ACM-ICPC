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
		if (toWell[i] != toWell[j] && isSegmentIntersect(pipeEnds[i],wells[toWell[i]],pipeEnds[j],wells[toWell[j]]) == 1)
			clause(2*i,2*j),clause(notC(2*i),notC(2*j));//,cout << i << " " << j << endl;
	
	kosa(2*P);
	
	bool fail = false;
	FOR(i,0,P) fail |= comp[2 * i] == comp[2 * i + 1];
	if (!fail) cout << "possible" << endl;
	else cout << "impossible" << endl;
}
