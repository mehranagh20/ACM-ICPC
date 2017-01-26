#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	string s;
	set<string> words;
	while (getline(cin, s)) {
		if (s == "") break;
		words.insert(s);
	}

	map< string, vector<string> > adj;

	for (set<string>::iterator i = words.begin(); i != words.end(); i++) {
		for (int j = 0; j < i->size(); j++) {
			string tmp = *i;
			for (char c = 'a'; c <= 'z'; c++) {
				tmp[j] = c;
				if (tmp != *i && words.find(tmp) != words.end()) {
					adj[*i].push_back(tmp);
				}
			}
		}
	}

	string a, b;
	bool first = true;
	while (cin >> a >> b) {
		if (!first)
			cout << endl;
		first = false;

		if (a.size() != b.size()) {
			cout << "No solution." << endl;
			continue;
		}

		queue<string> q; q.push(a);
		map<string, string> par; par[a] = a;

		vector<string> ans;
		while (!q.empty()) {
			s = q.front(); q.pop();
			if (s == b) {
				ans.push_back(s);
				while (s != par[s]) {
					s = par[s];
					ans.push_back(s);
				}
			}
			for (int i = 0; i < adj[s].size(); i++) {
				string nei = adj[s][i];
				if (par[nei].empty()) {
					par[nei] = s;
					q.push(nei);
				}
			}
		}

		if (!ans.empty()) {
			for (int i = ans.size() - 1; i >= 0; i--) {
				cout << ans[i] << endl;
			}
		} else {
			cout << "No solution." << endl;
		}
	}

	return 0;
}
