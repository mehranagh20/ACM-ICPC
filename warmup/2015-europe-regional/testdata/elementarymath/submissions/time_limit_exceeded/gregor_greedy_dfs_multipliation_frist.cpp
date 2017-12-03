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


int n;

ll as[2500];
ll bs[2500];



int st[2500];

set<ll> r;

void dfs(int d){
	if (d == n){
		FOR(i,0,n){
			ll nr = !st[i]?(as[i]*bs[i]):(st[i]==1?as[i]-bs[i]:as[i]+bs[i]);
			cout << as[i] << (!st[i]?('*'):(st[i]==1?'-':'+')) << bs[i] << '=' << nr << endl;
		}
		exit(0);
	}
	
	FOR(i,0,3){
		st[d] = i;
		ll nr = !st[d]?(as[d]*bs[d]):(st[d]==1?as[d]-bs[d]:as[d]+bs[d]);
		if (r.count(nr)) continue;
		r.insert(nr);
		dfs(d+1);
		r.erase(nr);
	}
}


int main(){
	cin >> n;
	FOR(i,0,n) cin >> as[i] >> bs[i];
	FOR(i,0,n) st[i] = 0;
	
	dfs(0);
	
	cout << "impossible" << endl;
	return 0;
}

















