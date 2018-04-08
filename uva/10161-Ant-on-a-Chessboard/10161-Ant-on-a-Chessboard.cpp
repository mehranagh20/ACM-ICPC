#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int f = sqrt(n - 1), c = ceil(sqrt(n));
        int rem = n - (f * f);
        if(f % 2) {
            if(rem < c) cout << rem << " " << c << endl;
            else cout << c << " " << c - (rem - c) << endl;
        }
        else {
            if(rem < c) cout << c << " " << rem << endl;
            else cout << c - (rem - c) << " " << c << endl;
        }
    }

    return 0;
}