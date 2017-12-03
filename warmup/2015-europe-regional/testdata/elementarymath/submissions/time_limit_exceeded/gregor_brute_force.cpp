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

bool check(){
	set<ll> r;
	FOR(i,0,n){
		ll nr = !st[i]?(as[i]+bs[i]):(st[i]==1?as[i]-bs[i]:as[i]*bs[i]);
		if (r.count(nr)) return false;
		r.insert(nr);
	}
	return true;
}

int main(){
	cin >> n;
	FOR(i,0,n) cin >> as[i] >> bs[i];
	
	FOR(i,0,n) st[i] = 0;
	
	int r = 0;
	while (true){
		if (check()){
			FOR(i,0,n){
				ll nr = !st[i]?(as[i]+bs[i]):(st[i]==1?as[i]-bs[i]:as[i]*bs[i]);
				cout << as[i] << (!st[i]?('+'):(st[i]==1?'-':'*')) << bs[i] << '=' << nr << endl;
			}
			return 0;
		}
		
		// go to next
		int c = 1;
		FOR(i,0,n){
			st[i]+= c;
			c = st[i] / 3;
			st[i] = st[i] % 3;
		}
		if (c) break;
	}
	
	cout << "impossible" << endl;
	return 0;
}

















