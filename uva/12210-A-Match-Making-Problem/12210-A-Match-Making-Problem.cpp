//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    int b, s, caseNum = 1;
    while(scanf("%d%d", &b, &s) && (b || s)) {
        printf("Case %d: ", caseNum++);
        int tmp, youngest = 1e8;
        for(int i = 0; i < b; i++){scanf("%d", &tmp); if(tmp < youngest) youngest = tmp;}
        for(int i = 0; i < s; i++) scanf("%d", &tmp);
        if(s >= b) printf("0\n");
        else printf("%d %d\n", b - s, youngest);

    }
}