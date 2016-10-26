#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int ans = 0, s = 0, tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp; s += tmp;
            if(s < 0) s = 0;
            ans = max(ans, s);
        }
        if(ans) printf("The maximum winning streak is %d.\n", ans);
        else printf("Losing streak.\n");
    }
    return 0;
}