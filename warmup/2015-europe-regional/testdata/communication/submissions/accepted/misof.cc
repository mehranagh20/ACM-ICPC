#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> preloz(256,-1);
    for (int n=0; n<256; ++n) {
        int x = (n ^ (n<<1)) & 255;
        preloz[x] = n;
    }
    int N;
    cin >> N;
    for (int n=0; n<N; ++n) { int x; cin >> x; cout << preloz[x] << (n+1==N ? "\n" : " "); }
}
