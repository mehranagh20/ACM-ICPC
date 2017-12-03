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

pii w[202];
int dp[202][202];

int main(){
	int N,P; cin >> N >> P;
	FOR(i,0,N) cin >> w[i].first >> w[i].second;
	
	vector<pii> ninc;
	vi overlap;
	
	FOR(i,0,N) FOR(j,0,N+1)
		if (i == j) continue;
		else if (j == N) ninc.push_back(w[i]);
		else if (w[i].first <= w[j].first && w[i].second >= w[j].second) {
			if (w[i].first == w[j].first && w[i].second == w[j].second && i < j) continue;
			overlap.push_back(w[i].second - w[i].first); break;
		}
	
	sort(all(ninc));
	FOR(i,0,sz(ninc))FOR(j,0,min(i,P)+1) dp[i][j] = -oo;
	dp[0][0] = 0;
	FOR(i,1,sz(ninc)+1) FOR(j,1,P+1) {
		dp[i][j] = dp[i-1][j-1] + ninc[i-1].second - ninc[i-1].first;
		FORD(k,1,i+1)
			if (ninc[k-1].second <= ninc[i-1].first) break;
			else if (dp[k-1][j-1] >= 0)
				dp[i][j] = max(dp[i][j],
							   dp[k-1][j-1] + ninc[k-1].second - ninc[i-1].first);
	}
	sort(all(overlap));
	reverse(all(overlap));
	FOR(i,1,sz(overlap)) overlap[i] += overlap[i-1];
	
	int m = dp[sz(ninc)][P];
	FOR(i,0,min(P-1,sz(overlap))) m = max(m,dp[sz(ninc)][P-i-1] + overlap[i]);
	cout << m << endl;
}
