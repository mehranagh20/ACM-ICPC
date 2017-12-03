#include <bits/stdc++.h>

using namespace std;
int diffs[][2] = {{0,0}, {1,0}, {0,1}, {1,1}}, c[2];

int main() {
	string s;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
		for (int j = 0; j < 2; j++) c[j] += (1 << (s.size()-i-1)) * diffs[s[i] - '0'][j];

	cout << s.size() << " " << c[0] << " " << c[1] << endl;
	return 0;
}
