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
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back
const int MX = 1e5 + 100;

char T[MX], P[MX]; // T = text, P = pattern
int pii, pjj;
int n, m; // size of text, size of pattern
vi b, all;

void kmpPreprocess() {
    b.assign(n + 1, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++;
        if (j == m) {
//            printf("P is found at index %d in T\n", i - j);
            all.push_back(i - j);
            j = b[j]; // prepare j for the next possible match
        }
    }
}

int main() {
    int q;
    cin >> n >> m >> q;
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s%s", T, P);
    kmpPreprocess(); kmpSearch();
    forn(i, q) {
        int l, r; cin >> l >> r;
        int ind1 = upper_bound(all.begin(), all.end(), l - 2) - all.begin();
        int ans = 0;
        for(int k = ind1; k < all.size(); k++)
            if(all[k] + m <= r) ans++;
        printf("%d\n", ans);
    }
    return 0;
}