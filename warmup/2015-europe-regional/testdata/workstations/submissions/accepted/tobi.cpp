#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
int N, M, walks, a, b;
vector<pair<int,bool>> logins;
multiset<int> active;

int main() {
	cin >> N >> M;
	FOR(i, 0, N) {
		cin >> a >> b;
		logins.push_back(make_pair(a,true));
		logins.push_back(make_pair(a+b,false));
	}
	sort(logins.begin(), logins.end());

	for (int i = 0; i < 2 * N; i++) {
		if (logins[i].second) {
			while (active.size() > 0 && *active.begin() < logins[i].first) active.erase(active.begin());
			if (active.size() > 0) active.erase(active.begin());
			else walks++;
		} else active.insert(logins[i].first + M);
	}
	cout << N-walks << endl;

	return 0;
}
