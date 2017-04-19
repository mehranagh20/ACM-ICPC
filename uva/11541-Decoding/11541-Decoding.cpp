//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    for(int i = 1; i <= n; i++) {
        getline(cin, s);
        stringstream ss(s);
        int num;
        char c;
        printf("Case %d: ", i);
        while(ss >> c >> num) {
            for(int i = 0; i < num; i++) putchar(c);
        }
        puts("");
    }
}