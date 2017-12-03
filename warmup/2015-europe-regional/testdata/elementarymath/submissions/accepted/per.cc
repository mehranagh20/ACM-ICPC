#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll num[5000][2], vals[7500];
map<ll, int> rhs;
vi adj[5000];
int lmate[5000], rmate[7500], seen[5000];

void link(int i, ll v) {
	int &r = rhs[v];
	if (!r) r = rhs.size(), vals[r] = v;
	adj[i].push_back(r);
}

bool bump(int i, int c) {
	if (seen[i] == c) return false;
	seen[i] = c;
	for (auto r: adj[i]) {
		if (r != lmate[i] && (!rmate[r] || bump(rmate[r], c))) {
			lmate[i] = r;
			rmate[r] = i;
			return true;
		}
	}
	return false;
}

int main(void) {
	int n;
	scanf("%d", &n);
	memset(lmate, 0, sizeof(lmate));
	memset(rmate, 0, sizeof(lmate));
	memset(seen, 0, sizeof(seen));
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", num[i], num[i]+1);
		link(i, num[i][0]+num[i][1]);
		link(i, num[i][0]-num[i][1]);
		link(i, num[i][0]*num[i][1]);
		if (!bump(i, i)) {
			printf("impossible\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		ll v = vals[lmate[i]];
		printf("%lld%c%lld=%lld\n", 
			   num[i][0], (num[i][0]+num[i][1] != v ? num[i][0]-num[i][1] != v ? '*' : '-' : '+'), num[i][1], v);
	}
}
