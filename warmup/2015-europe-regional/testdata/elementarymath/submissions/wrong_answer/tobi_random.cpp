#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
vector<int> adj[2505];
map<ll,int> notoint;
ll a[2505], b[2505], idtores[7505], res[2505];
int N, nodes;
map<ll,int> usedby, usedCnt;
vector<int> dups;
bool isPoss = false;

int get(ll x) {
	if (!notoint.count(x)) {
		notoint[x] = nodes++;
		idtores[notoint[x]] = x;
	}
	return notoint[x];
}

bool checkDups() {
	dups.clear(); usedby.clear(); usedCnt.clear();
	FOR(i, 0, N) {
		if (usedCnt[res[i]] == 1) dups.push_back(usedby[res[i]]);
		if (usedCnt[res[i]] > 0) dups.push_back(i);
		usedCnt[res[i]]++;
		usedby[res[i]] = i;
	}
	return isPoss = dups.size() == 0;
}

bool greed(const int &x, const int &y) {
	for (int i = 0; i < 2; i++) {
		ll left = idtores[adj[x][i]], right = idtores[adj[y][i]];
		if (left != right) return left < right;
	}
	return false;
}

int main() {
	srand(time(0));
	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		adj[i].push_back(get(a[i]+b[i]));
		adj[i].push_back(get(a[i]-b[i]));
		adj[i].push_back(get(a[i]*b[i]));
	}
	FOR(i, 0, 2000000/N) {
		if (checkDups()) break;
		sort(dups.begin(), dups.end(), greed);
		for (int j : dups) {
			usedCnt[res[j]]--;
			bool found = false;
			FOR(k, 0, 3) {
				if (usedCnt[idtores[adj[j][k]]] == 0) {
					res[j] = idtores[adj[j][k]];
					found = true;
					break;
				}
			}
			if (!found) res[j] = idtores[adj[j][rand()%3]];
			usedCnt[res[j]]++;
		}
	}
	if (!isPoss) cout << "impossible" << endl;
	else {
		FOR(i, 0, N) {
			char c = '+';
			if (a[i]*b[i] == res[i]) c = '*';
			else if (a[i]-b[i] == res[i]) c = '-';
			cout << a[i] << c << b[i] << "=" << res[i] << endl;
		}
	}
	
	return 0;
}
