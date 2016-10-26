#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int a, b, c;
    while(cin >> a >> b >> c && (a || b || c)) {
        if(a < 8 || b < 8) cout << "0\n";
        else {
            if(!c) {
                if (a == 8 && b == 8) cout << "0\n";
                else cout << (int) ceil(((a - 8) * (b - 7) + (a - 7) * (b - 8) - (a - 8) * (b - 8)) / 2.) << endl;
            }
            else cout << (int)ceil((double)(a - 7) * (b - 7) / 2) << endl;
        }
    }

    return 0;
}