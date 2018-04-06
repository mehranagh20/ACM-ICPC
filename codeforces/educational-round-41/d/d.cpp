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
#define inf 1000000000 + 1
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int p1, p2;
int n;
vii ps;
int f1, f2;

vi vis;
void check() {
    if(p1 != -1) vis[p1] = 1;
    if(p2 != -1) vis[p2] = 1;
    if(p1 == -1 || p2 == -1) return;
    f1 = f2 = -1;
    int x = abs(ps[p1].F - ps[p2].F), y = abs(ps[p1].S - ps[p2].S);
    int a = gcd(x, y);
    x /= a, y /= a;


    for(int i = 0; i < n; i++) if(ps[i] != ps[p1] && ps[i] != ps[p2]) {
            int x2 = abs(ps[p1].F - ps[i].F), y2 = abs(ps[p1].S - ps[i].S);
            int tmp = gcd(x2, y2);
            x2 /= tmp, y2 /= tmp;
            if(x != x2 || y != y2) {
                if(f1 == -1) {
                    f1 = i;
                    continue;
                }
                if(f2 == -1)
                    f2 = i;
                continue;
            }
            x2 = abs(ps[p2].F - ps[i].F), y2 = abs(ps[p2].S - ps[i].S);
            tmp = gcd(x2, y2);
            x2 /= tmp, y2 /= tmp;
            if(x != x2 || y != y2) {
                if (f1 == -1) {
                    f1 = i;
                    continue;
                }
                if (f2 == -1)
                    f2 = i;
                continue;
            }
            vis[i] = 1;
        }

}

bool ok() {
    for(auto &e: vis) if(!e) return false;
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    scanf("%d", &n);

    ps.assign(n, ii());
    for(auto &e: ps) scanf("%d%d", &e.F, &e.S);
    if(n <= 4) {
        printf("YES");
        return 0;
    }

    bool isok = false;
    vis.assign(n, 0);
    p1 = 0, p2 = 1; check();
    p1 = f1, p2 = f2; check();
    isok |= ok();

    vis.assign(n, 0);
    p1 = 0, p2 = 2; check();
    p1 = f1, p2 = f2; check();
    isok |= ok();

    vis.assign(n, 0);
    p1 = 1, p2 = 2; check();
    p1 = f1, p2 = f2; check();
    isok |= ok();

    if(isok) cout << "YES";
    else cout << "NO";

    return 0;
}