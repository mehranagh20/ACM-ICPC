#include <iostream>

using namespace std;

int main() {
	int table[256], n, tmp;
	for (int i = 0; i < 256; i++) table[(i^(i<<1)) % 256] = i;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cout << table[tmp] << ' ';
	}

	return 0;
}
