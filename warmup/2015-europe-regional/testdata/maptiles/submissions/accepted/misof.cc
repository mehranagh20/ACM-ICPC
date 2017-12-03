#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    reverse( S.begin(), S.end() );
    unsigned x=0, y=0, i;
    for (i=0; i<S.size(); ++i) {
        if (S[i]=='1' || S[i]=='3') x += 1<<i;
        if (S[i]=='2' || S[i]=='3') y += 1<<i;
    }
    cout << S.size() << " " << x << " " << y << endl;
}
