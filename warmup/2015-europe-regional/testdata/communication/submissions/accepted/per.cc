#include <bits/stdc++.h>

int main(void) {
	int N, enc[256];
	scanf("%d", &N);
	for (int i = 0; i < 256; ++i) enc[(i ^ (i<<1)) & 0xFF] = i;
	for (int i = 0, y; i < N; ++i, scanf("%d", &y),	printf("%d\n", enc[y]));
	return 0;
}
