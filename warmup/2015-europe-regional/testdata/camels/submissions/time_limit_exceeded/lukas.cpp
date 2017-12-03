//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi inv(vi &a)
{
    vi res(a.size());
    rep(i,0,a.size()) res[a[i]] = i;
    return res;
}
int main()
{
    int n; scanf("%d", &n);

    vi a(n), b(n), c(n);
    rep(i,0,n) scanf("%d", &a[i]), a[i]--;
    rep(i,0,n) scanf("%d", &b[i]), b[i]--;
    rep(i,0,n) scanf("%d", &c[i]), c[i]--;

    vi ia = inv(a), ib = inv(b), ic = inv(c);

    ll res = 0;
    rep(i,0,n) rep(j,0,i)
    {
        bool oa = ia[i] < ia[j];
        bool ob = ib[i] < ib[j];
        bool oc = ic[i] < ic[j];
        res += (oa == ob) && (oa == oc);
    }

    cout << res << endl;
}
