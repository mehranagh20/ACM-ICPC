//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int main()
{
    int n;
    scanf("%d", &n);
    bitset<30> mask(255);

    int c;
    rep(i,0,n)
    {
        scanf("%d", &c);
        bitset<30> b(c);
        rep(j,0,30)
            b[j + 1] = b[j + 1] ^ b[j];
        printf("%d%s", (int)(b & mask).to_ulong(), i + 1 < n ? " " : "\n");
    }
}
