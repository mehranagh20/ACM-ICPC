//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int t, n, ans;
string s;

int cal(int i) {
    for(i; i < n; i++)
        if(s[i] == '.') {
            ans++;
            return i + 3;
        }
    return i;
}

int main() {
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        ans = 0;
        scanf("%d", &n);
        while(getchar() != '\n');
        getline(cin, s);
        int j = 0;
        while((j = cal(j)) < n);
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}