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

const int mx = 1000010;
char seq[mx];
int nxt[mx];
int prv[mx];
int present[mx];
int n;

void remove(int i) {
    if (prv[i] >= 0) nxt[prv[i]] = nxt[i];
    if (nxt[i] < n) prv[nxt[i]] = prv[i];
}

bool crit(int i) {
    if(i >= n || i < 0) return false;
    if(prv[i] >= 0 && seq[prv[i]] != seq[i]) return true;
    if(nxt[i] < n && seq[nxt[i]] != seq[i]) return true;
    return false;
}

int main() {
    scanf("%s", seq);
    n = strlen(seq);
    for(int i = 0; i < n; i++) nxt[i] = i + 1, prv[i] = i - 1;
    vi cur;
    for(int i = 0; i < n; i++)
        if(crit(i)) cur.push_back(i), present[i] = 1;

    int ans = 0;

    while(cur.size()) {
        ans++;
        vi nxt_cur;
        for(auto i: cur) remove(i);
        for(auto i: cur) {
            if(!present[prv[i]] && crit(prv[i]))
                nxt_cur.push_back(prv[i]), present[prv[i]] = 1;
            if(!present[nxt[i]] && crit(nxt[i]))
                nxt_cur.push_back(nxt[i]), present[nxt[i]] = 1;
        }
        cur = nxt_cur;
    }

    printf("%d\n", ans);


    return 0;
}
