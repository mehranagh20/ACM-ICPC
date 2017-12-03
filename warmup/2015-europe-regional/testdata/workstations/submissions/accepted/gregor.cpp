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


pii r[350000];


int main(){
	int n,m; cin >> n >> m;
	FOR(i,0,n) cin >> r[i].first >> r[i].second;
	sort(r,r+n);
	priority_queue<int> q;
	int w = 0;
	FOR(i,0,n){
		while (!q.empty()){
			if (-q.top() > r[i].first) break;
			if (-q.top() + m >= r[i].first) { w++; q.pop(); break; }
			q.pop();
		}
		
		q.push(-r[i].first-r[i].second);
	}
	
	cout << w << endl;
}
