//Solution by lukasP (Lukáš Poláček)
//Complexity O(n * sqrt(n))
#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>
#include <cmath>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef vector<int> vi;
struct SqrtBuckets {
    int n, size;
    vector<int> s, buckets;
    SqrtBuckets(int _n) : n(_n) {
        s.assign(n, 0);
        size = ceil(sqrt(n));
        buckets.assign((n + size - 1) / size, 0);
    }
    void update(int pos, int dif) {
        s[pos] += dif;
        buckets[pos / size] += dif;
    }
    int query(int pos) {
        int buck_num = pos / size;
        int buck_sum = accumulate(buckets.begin(), buckets.begin() + buck_num, 0);
        int array_sum = accumulate(s.begin() + buck_num * size, s.begin() + pos, 0);
        return buck_sum + array_sum;
    }
};

// Count the number of pairs on which two permutations disagree
ll inversions(vi &a, vi &b)
{
    vi inv(a.size());
    rep(i,0,a.size()) inv[a[i]] = i;

    SqrtBuckets t(a.size());
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
