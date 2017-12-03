//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef vector<int> vi;
struct FenwickTree {
    int n;
    vector<int> s;
    FenwickTree(int _n) : n(_n) {
        s.assign(n, 0);
    }
    void update(int pos, int dif) {
        for (; pos < n; pos |= pos + 1)
            s[pos] += dif;
    }
    int query(int pos) {
        int count = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            count += s[pos];
        return count;
    }
};

// Count the number of pairs on which two permutations disagree
ll inversions(vi &a, vi &b)
{
    vi inv(a.size());
    rep(i,0,a.size()) inv[a[i]] = i;

    FenwickTree t(a.size());
    ll res = a.size() * (a.size() - 1) / 2;
    for (int x : b)
    {
        res -= t.query(inv[x]);
        t.update(inv[x], 1);
    }
    return res;
}

int main()
{
    int n; scanf("%d", &n);

    vi a(n), b(n), c(n);
    rep(i,0,n) scanf("%d", &a[i]), a[i]--;
    rep(i,0,n) scanf("%d", &b[i]), b[i]--;
    rep(i,0,n) scanf("%d", &c[i]), c[i]--;

    ll inverse = inversions(a, b) + inversions(a, c) + inversions(b, c);
    ll total = n * ll(n - 1) / 2;
    cout << total - inverse / 2 << endl;
}
