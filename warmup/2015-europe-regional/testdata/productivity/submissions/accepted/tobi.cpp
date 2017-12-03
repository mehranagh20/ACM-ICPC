#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
int N, P, best, dp[205][205], dp2[205][205], IS, NIS;
pair<int,int> ivs[100000];
vector<pair<int,int>> noninclusive;
vector<int> inclusive;
bool comp[205][205];

int rec(int start, int groupsLeft) {
	if (groupsLeft == 0) return start == NIS ? 0 : -1;
	if (start == NIS) return -1;
	if (comp[start][groupsLeft]) return dp2[start][groupsLeft];
	int ret = -1;
	FOR(i, start, NIS) {
		int tmp = rec(i+1, groupsLeft-1);
		if (dp[start][i] > 0 && (tmp > 0 || (tmp == 0 && i+1 == NIS && groupsLeft == 1))) ret = max(ret, dp[start][i] + tmp);
	}
	comp[start][groupsLeft] = true;
	return dp2[start][groupsLeft] = ret;
}

int main() {
	cin >> N >> P;
	FOR(i, 0, N) cin >> ivs[i].first >> ivs[i].second;
	FOR(i, 0, N) {
		bool outside = false;
		FOR(j, 0, N) if (i != j && ivs[i].first < ivs[j].first && ivs[j].second < ivs[i].second) outside = true;
		if (outside) inclusive.push_back(ivs[i].second - ivs[i].first);
		else noninclusive.push_back(ivs[i]);
	}
	sort(noninclusive.begin(), noninclusive.end());
	sort(inclusive.begin(), inclusive.end());
	NIS = noninclusive.size(), IS = inclusive.size();
	FORD(i, 1, IS) inclusive[i-1] += inclusive[i];

	FOR(i, 0, NIS) FOR(j, i, NIS) dp[i][j] = noninclusive[i].second - noninclusive[j].first;

	inclusive.push_back(0);
	FOR(i, 0, min(P, IS+1)) {
		int tmp = rec(0, P-i);
		if (tmp > 0 || (tmp == 0 && i == P && NIS == 0)) best = max(best, tmp + inclusive[IS-i]);
	}
	cout << best << endl;

	return 0;
}
