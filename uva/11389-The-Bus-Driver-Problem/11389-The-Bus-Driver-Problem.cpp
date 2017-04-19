//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, r;
    while(scanf("%d%d%d", &n, &d, &r) && (n || d || r)) {
        vector<int> f(n), s(n);
        for (int i = 0; i < n; i++) scanf("%d", &f[i]);
        for (int i = 0; i < n; i++) scanf("%d", &s[i]);
        int ans = 0;
        sort(s.begin(), s.end()); sort(f.begin(), f.end());
        for(int i = 0; i < n; i++)
            ans += (f[i] + s[n - i - 1] > d ? -d + (f[i] + s[n - i - 1]) : 0);
        printf("%d\n", ans * r);
    }
    return 0;
}