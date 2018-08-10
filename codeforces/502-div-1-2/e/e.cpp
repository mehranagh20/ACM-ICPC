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
typedef vector<ll> vi;
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
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

double cross(dd O, dd A, dd B) {
    return (A.first - O.first) * (B.second - O.second) -
           (A.second - O.second) * (B.first - O.first);
}

vdd convexHull(vdd P){
    int n = P.size(),k = 0; vdd H(2*n);
    sort(P.begin(), P.end());
    for(int i = 0; i < n; i++){
        while(k >= 2 && cross(H[k - 2], H[k - 1] , P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--){
        while(k >= t && cross(H[k - 2], H[k - 1] , P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k); return H;
}

dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }
double dot(dd a, dd b) { return (a.first * b.first + a.second * b.second); }
double norm_sq(dd v) { return v.first * v.first + v.second * v.second; }

double angle(dd a, dd o, dd b) {
    dd oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double dist(dd p1, dd p2){
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

bool eq(double a, double b) {
    return abs(a - b) < eps;
}

vi b;
vd P, T;
bool found = false;

void kmpPreprocess() {
    b.assign(T.size() + 1, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < P.size()) {
        while (j >= 0 && !eq(P[i], P[j])) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch() {
    int i = 0, j = 0;
    while (i < T.size()) {
        while (j >= 0 && !eq(T[i], P[j])) j = b[j];
        i++; j++;
        if (j == P.size()) {
            found = true;
            j = b[j];
        }
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vdd a(n), b(m);
    forn(i, n) scanf("%lf%lf", &a[i].first, &a[i].second);
    forn(i, m) scanf("%lf%lf", &b[i].first, &b[i].second);

    vdd ca = convexHull(a), cb = convexHull(b);
    ca.pop_back(), cb.pop_back();

    int sz = ca.size();
    forn(i, sz) ca.push_back(ca[i]);

    forn(i, ca.size()) {
        int pr = i - 1, cu = i, nx = i + 1;
        if(nx >= ca.size()) nx = 0;
        if(pr < 0) pr = ca.size() - 1;
        T.push_back(dist(ca[pr], ca[cu])), T.push_back(angle(ca[pr], ca[cu], ca[nx]));
    }

    forn(i, cb.size()) {
        int pr = i - 1, cu = i, nx = i + 1;
        if(nx >= cb.size()) nx = 0;
        if(pr < 0) pr = cb.size() - 1;
        P.push_back(dist(cb[pr], cb[cu])), P.push_back(angle(cb[pr], cb[cu], cb[nx]));
    }

    kmpPreprocess(), kmpSearch();

    if(found) printf("yes\n");
    else printf("no\n");


    return 0;
}