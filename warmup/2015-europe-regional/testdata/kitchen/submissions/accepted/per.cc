#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll oo = 1000000000000000001LL;
void read_dish(vi &D) {
	int k;
	scanf("%d", &k);
	D.resize(k);
	for (int i = 0; i < k; ++i) scanf("%d", &D[i]);
}

int main(void) {
	int r, s, m, d, n;
	scanf("%d%d%d%d%d", &r, &s, &m, &d, &n);
	vi brands(r+1);
	for (int i = 1; i <= r; ++i) scanf("%d", &brands[i]);
	vector<vi> dishes(s+m+d);
	for (int i = 0; i < s+m+d; ++i)	read_dish(dishes[i]);
	int conflict[200][200];
	memset(conflict, 0, sizeof(conflict));
	for (int i = 0; i < n; ++i) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		conflict[a1-1][a2-1] = conflict[a2-1][a1-1] = true;
	}
	ll res = 0;
	for (int i = 0; i < s; ++i)
		for (int j = s; j < s+m; ++j)
			for (int k = s+m; k < s+m+d; ++k) {
				if (conflict[i][j] || conflict[i][k] || conflict[j][k])
					continue;
				set<int> ingreds;
				copy(dishes[i].begin(), dishes[i].end(), inserter(ingreds, ingreds.begin()));
				copy(dishes[j].begin(), dishes[j].end(), inserter(ingreds, ingreds.begin()));
				copy(dishes[k].begin(), dishes[k].end(), inserter(ingreds, ingreds.begin()));
				ll t = 1;
				for (int x: ingreds) {
					if (t > oo/brands[x]) t = oo;
					else t *= brands[x];
				}
				if (res + t >= oo) res = oo;
				else res += t;
			}
	if (res >= oo) printf("too many\n");
	else printf("%lld\n", res);
}
