#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) &&n) {
        printf("The parity of ");
        bool st = false;
        for(int i = 1 << 30; i >= 1; i >>= 1) {
            if(n & i)
                st = true;
            if(st) {
                if(n & i)
                    cout << "1";
                else
                    cout << "0";
            }
        }
        cout << " is ";
        int num = 0;
        for(int i = 0; i < 31; i++) {
            int tmp = 1;
            if(n & (tmp << i))
                num++;
        }
        printf("%d (mod 2).\n", num);
    }

    return 0;
}

