#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pii> ev(2*n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		ev[2*i] = pii(a, 1);
		ev[2*i+1] = pii(a+b, -1);
	}
	sort(ev.begin(), ev.end());
	priority_queue<int> q;
	int walks = 0;
	for (auto e: ev) {
		if (e.second < 0) q.push(-e.first-m);
		else {
			while (!q.empty() && -q.top() < e.first) q.pop();
			if (!q.empty()) q.pop(), ++walks;
		}
	}
	printf("%d\n", walks);
	return 0;
}
