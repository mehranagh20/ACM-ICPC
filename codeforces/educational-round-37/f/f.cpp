//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vector<ll> seg;

ll sum(int p, int l, int r, int wl, int wr) {
    if(wr < l || wl > r) return 0;
    if(l >= wl && r <= wr) return seg[p];
    return sum(p * 2, l, (r + l) / 2, wl, wr) + sum(p * 2 + 1, (r + l) / 2 + 1, r, wl, wr);
}

void update(int x, int i, int p, int l, int r) {
    if(i == l && i == r) {
        seg[p] = x;
        return;
    }
    if(i < l || i > r) return;
    update(x, i, p * 2, l, (l + r) / 2);
    update(x, i, p * 2 + 1, (l + r) / 2 + 1, r);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int main() {
    int n, m, mx = 1e6 + 100;
    scanf("%d%d", &n, &m);
    vi numdiv(mx, 1);
    set<ii> s;
    seg.assign(mx * 3, 0);
    for (int k = 0; k < n; ++k) {
        int a; cin >> a;
        update(a, k, 1, 0, n - 1);
        if(a >= 3)
            s.insert(ii(k, a));
    }

    for (int i = 2; i < mx; i++)
            for (int j = i; j < mx; j += i)
                numdiv[j]++;

    while(m--) {
        int t, r, l; scanf("%d%d%d", &t, &l, &r);
        l--, r--;
        if(t == 1) {
            while(1) {
                auto it = s.lower_bound(ii(l, -1));
                if(it == s.end() || it->first > r) break;
                update(numdiv[it->second], it->first, 1, 0, n - 1);
                l = it->first + 1;
                if(numdiv[it->second] < 3) s.erase(it);
                else {
                    ii t = *it;
                    s.erase(it);
                    s.insert(ii(t.first, numdiv[t.second]));
                }
            }
        }
        else {
            printf("%lld\n", sum(1, 0, n - 1, l, r));
        }
    }


    return 0;
}