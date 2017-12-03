// solution using standard max-flow
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

struct edge {
	int to, cap, flow, oi;
};

#define MAXN 12502

vector<edge> e[MAXN];
int aug[MAXN];
int pa[MAXN];

void addEdge(int u, int v, int capUV, int capVU) {
	edge uv, vu;
	uv.to = v;
	uv.cap = capUV;
	uv.flow = 0;
	uv.oi = e[v].size();

	vu.to = u;
	vu.cap = capVU;
	vu.flow = 0;
	vu.oi = e[u].size();

	e[u].push_back(uv);
	e[v].push_back(vu);
}

bool findAugPathEK(int src, int sink, int n) {
	static int qu[MAXN]; // pseudo-queue

	FOR(i,0,n)
		pa[i] = -1;
	aug[src] = oo;

	int start = 0, end = 0;
	qu[end++] = src;
	while (start != end) {
		int u = qu[start++];
		FOR(i,0,sz(e[u])) {
			int v = e[u][i].to;
			int curaug = e[u][i].cap - e[u][i].flow;
			if (pa[v] == -1 && curaug > 0) {
				qu[end++] = v;
				aug[v] = min(aug[u], curaug);
				pa[v] = e[u][i].oi;
				if (v == sink)
					return true;
			}
		}
	}
	return false;
}

int calcMaxFlow(int src, int sink, int n) {
	int ret = 0;
	FOR(i,0,n)
		FOR(j,0,sz(e[i]))
			e[i][j].flow = 0;

	while (findAugPathEK(src, sink, n)) {
		int v = sink;
		while (v != src) {
			e[e[v][pa[v]].to][e[v][pa[v]].oi].flow += aug[sink];
			e[v][pa[v]].flow -= aug[sink];
			v = e[v][pa[v]].to;
		}
		ret += aug[sink];
		if (ret >= oo)
			break;
	}
	return ret;
}


map<ll,int> rightT;



int getRight(ll i){
	if (!rightT.count(i)) rightT[i] = sz(rightT)-1;
	return rightT[i];
}

ll as[2500];
ll bs[2500];

int main(){
	int n; cin >> n;
	FOR(i,0,n){
		cin >> as[i] >> bs[i];
		addEdge(0,2+i,1,0);

		addEdge(2+i,2+n+getRight(as[i]+bs[i]),1,0);
		addEdge(2+i,2+n+getRight(as[i]-bs[i]),1,0);
		addEdge(2+i,2+n+getRight(as[i]*bs[i]),1,0);
	}

	FORIT(i,rightT) addEdge(2+n+i->second,1,1,0);
	
	int mf = calcMaxFlow(0,1,2+n+sz(rightT));
	
	if (mf != n) cout << "impossible" << endl;
	else
		FOR(i,0,n) FOR(j,0,sz(e[i+2]))
			if (e[i+2][j].flow) {
				if (e[i+2][j].to == 2+n+getRight(as[i]+bs[i]))
					cout << as[i] << '+' << bs[i] << '=' << as[i]+bs[i] << endl;
				else if (e[i+2][j].to == 2+n+getRight(as[i]-bs[i]))
					cout << as[i] << '-' << bs[i] << '=' << as[i]-bs[i] << endl;
				else if (e[i+2][j].to == 2+n+getRight(as[i]*bs[i]))
					cout << as[i] << '*' << bs[i] << '=' << as[i]*bs[i] << endl;
			}
}


























