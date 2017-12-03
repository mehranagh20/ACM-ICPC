//Solution by lukasP (Lukáš Poláček)
//Complexity O(n log n), idea similar to Eratosthenes sieve
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef vector<ll> vl;
int main()
{
    int n, t, c;
    scanf("%d %d %d", &n, &t, &c);

    vl best(2 * n, 1LL<<60);
    best[1] = 0;
    rep(i,1,best.size())
    {
        for (int j = 2; j * i < best.size(); j++)
            best[j * i] = min(best[j * i], best[i] + ll(j - 1) * c + t);
    }
    cout << *min_element(best.begin() + n, best.end()) << endl;
}
