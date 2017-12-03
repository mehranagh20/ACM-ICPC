#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
vector<int> adj[2505];
map<int,int> notoint;
int N, a[2505], b[2505], nodes, idtores[7505], pred[7505], res[2505];
bool mark[7505];

bool match(int n) {
        if (n == -1) return true;
        for (int to : adj[n]) {
                if (mark[to]) continue;
                mark[to] = true;
                if (match(pred[to])) {
                        pred[to] = n;
                        return true;
                }
        }
        return false;
}

int maxmatch() {
        fill_n(pred, 7505, -1);
        int ret = 0;
        FOR(i, 0, N) {
                fill_n(mark, 7505, false);
                if (match(i)) ret++;
        }
        return ret;
}

int get(int x) {
	if (!notoint.count(x)) {
		notoint[x] = nodes++;
		idtores[notoint[x]] = x;
	}
	return notoint[x];
}

int main() {
	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		adj[i].push_back(get(a[i]+b[i]));
		adj[i].push_back(get(a[i]*b[i]));
		adj[i].push_back(get(a[i]-b[i]));
	}

	if (maxmatch() < N) cout << "impossible" << endl;
	else {
		FOR(i, 0, nodes) if (pred[i] >= 0) res[pred[i]] = idtores[i];
		FOR(i, 0, N) {
			char c = '+'; // XXX: should lead to correct expressions but duplicates
			// if (a[i]*b[i] == res[i]) c = '*';
			// else if (a[i]-b[i] == res[i]) c = '-';
			cout << a[i] << c << b[i] << "=" << a[i]+b[i] << endl;
		}
	}

	return 0;
}
