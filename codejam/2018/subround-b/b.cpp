//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

struct st {
    int d, a, b;
};
struct mx_res {
    int m, n, i, j, mx;
};

int num = 0, tot = 0;
vector<st> al;

void doUpdate(int i) {
    if(num < i) num = i, tot = 1;
    else if(i == num) tot++;
}

mx_res give_mx(int i, int j, int add, int m, int n) {
    int mx = 0, tmp = i;
    while(i != j) {
        int mm = al[i].d + al[i].a, nn = al[i].d - al[i].b;
        if(mm == m || nn == n) {
            mx++, i += add;
            continue;
        }
        if(m == inf) {
            m = al[i].d + al[i].a, mx++, i += add;
            continue;
        }
        else if(n == inf) {
            n = al[i].d - al[i].b, mx++, i += add;
            continue;
        } else
            break;
    }
    int k = tmp, k2 = i - add;
    if(add == -1) k = i - add, k2 = tmp;
    return {m, n, k, k2, mx};
}

void solve(int i, int j) {
    if(j - i + 1 <= 2) {
        doUpdate(j - i + 1);
        return;
    }
    solve(i, (i + j) / 2 - 1), solve((i + j) / 2 + 1, j);
    int mid = (i + j) / 2;
    int m = al[mid].d + al[mid].a, n = al[mid].d - al[mid].b;
    mx_res r1 = give_mx(mid + 1, j + 1, 1, m, inf);
    mx_res r2 = give_mx(mid + 1, j + 1, 1, inf, n);
    mx_res r3 = give_mx(mid - 1, i - 1, -1, m, inf);
    mx_res r4 = give_mx(mid - 1, i - 1, -1, inf, n);

    set<ii> cur;
    mx_res b1 = give_mx(mid + 1, j + 1, 1, m, r1.n);
    mx_res b11 = give_mx(mid - 1, i - 1, -1, m, r1.n);
    if(cur.find(ii(b11.i, b1.j)) == cur.end())
        doUpdate(b1.mx + b11.mx + 1), cur.insert(ii(b11.i, b1.j));


    b1 = give_mx(mid + 1, j + 1, 1, m, r3.n);
    b11 = give_mx(mid - 1, i - 1, -1, m, r3.n);
    if(cur.find(ii(b11.i, b1.j)) == cur.end())
        doUpdate(b1.mx + b11.mx + 1), cur.insert(ii(b11.i, b1.j));

    b1 = give_mx(mid + 1, j + 1, +1, r2.m, n);
    b11 = give_mx(mid - 1, i - 1, -1, r2.m, n);
    if(cur.find(ii(b11.i, b1.j)) == cur.end())
        doUpdate(b1.mx + b11.mx + 1), cur.insert(ii(b11.i, b1.j));

    b1 = give_mx(mid + 1, j + 1, +1, r4.m, n);
    b11 = give_mx(mid - 1, i - 1, -1, r4.m, n);
    if(cur.find(ii(b11.i, b1.j)) == cur.end())
        doUpdate(b1.mx + b11.mx + 1), cur.insert(ii(b11.i, b1.j));

}


int main() {
    int t; scanf("%d", &t);
    forn(tc, t) {
        int n; cin >> n;
        al.assign(n, st());
        forn(i, n) scanf("%d%d%d", &al[i].d, &al[i].a, &al[i].b);
        num = tot = 0;
        solve(0, n - 1);
        printf("Case #%d: %d %d\n", tc + 1, num, tot);
    }

    return 0;
}