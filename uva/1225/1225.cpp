#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int num;
        scanf("%d", &num);
        vector<int> count(10, 0);
        for(int i = 1; i <= num; i++) {
            string str = to_string(i);
            for(auto &e : str)
                count[e - '0']++;
        }
        int j = 0;
        for(auto &e : count) {
            if(j++)
                printf(" ");
            printf("%d", e);
        }
        puts("");
    }

    return 0;
}

