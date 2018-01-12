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

set<iii> s;
int k, k1, k2, k3;

bool cycle(int x1, int x2, int x3) {
	if (s.find(iii(x1, ii(x2, x3))) != s.end())
		return true;
	int p1 = x1, p2 = x2, p3 = x3;
	bool ans = true;
	for (int i = 0; i < k; i++) {
		bool cur = false;
		if (p1 < k && p1 == i) {
			p1 += k1;
			cur = true;
		}
		if (p2 < k && p2 == i) {
			p2 += k2;
			cur = true;
		}
		if (p3 < k && p3 == i) {
			p3 += k3;
			cur = true;
		}
		if (!cur)
			return false;
	}
	s.insert(iii(x1, ii(x2, x3)));
	return cycle(p1 % k, p2 % k, p3 % k);
}

int main() {
	ios::sync_with_stdio(false);

	cin >> k1 >> k2 >> k3;
	k = max(k1, max(k2, k3));
	if (k1 < k && k2 == k)
		swap(k1, k2);
	if (k1 < k && k3 == k)
		swap(k1, k3);

	bool ans = false;
	ans |= cycle(0, 0, 0);
	s.clear();
	ans |= cycle(0, 0, 1);
	s.clear();
	ans |= cycle(0, 1, 0);
	s.clear();
	ans |= cycle(0, 1, 1);
	s.clear();
	ans |= cycle(0, 1, 2);
	s.clear();
	ans |= cycle(0, 2, 1);

	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}