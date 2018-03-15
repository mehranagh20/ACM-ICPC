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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vvi children;
vi L, E, H;
int idx;
vi w;

void dfs(int cur, int depth, int p) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for (int i = 0; i < children[cur].size(); i++) {
        if(children[cur][i] == p) continue;
        dfs(children[cur][i], depth+1, cur);
        E[idx] = cur; // backtrack to current node
        L[idx++] = depth;
    }
}

void buildRMQ() {
    idx = 0;
    dfs(0, 0, -1); // we assume that the root is at index 0
}

struct RMQ { // construct rmq in n * log(n), takes n * log(n) space. query in O(1).
    int len;
    vvi rmq;
    vvi ind;

    void init(vi arr) { // call this method with your desired array.
        len = arr.size();
        int lg = log(len) / log(2) + 2;
        rmq.assign(len + 10, vi(lg, 0));
        ind.assign(len + 10, vi(lg, 0));
        for (int i = 0; i < len; i++)
            rmq[i][0] = arr[i], ind[i][0] = i;
        for (int j = 1; j < lg; j++)
            for (int i = 0; i < len; i++) {
                if (i + (1 << j) > len)
                    break;
                if(rmq[i][j - 1] < rmq[i + (1 << (j - 1))][j - 1])
                    rmq[i][j] = rmq[i][j - 1], ind[i][j] = ind[i][j - 1];
                else
                    rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1], ind[i][j] = ind[i + (1 << (j - 1))][j - 1];
            }
    }

    ii range_minimum_query(int l, int r) { // it is 0 base, manage so that 'l' and 'r' are in range!, first element is the min element, second element is index of min element in the range.
        if (l > r)
            swap(l, r);

        int interval_len = r - l;

        int first_half = 1;
        while ((1 << first_half) <= interval_len)
            first_half++;
        first_half--;

        int second_half = r - (1 << first_half) + 1;
        if(rmq[l][first_half] < rmq[second_half][first_half]) return ii(rmq[l][first_half], ind[l][first_half]);
        else return ii(rmq[second_half][first_half], ind[second_half][first_half]);

    }
};

int cnt = 0;
vi l, r, oc;
void dfss(int i, int p) {
    oc.push_back(i);
    l[i] = cnt++;
    for(auto &e: children[i]) if(e != p)
            dfss(e, i);
    r[i] = cnt++;
    oc.push_back(i);
}

RMQ rmq;

struct rng {
    int l, r, i, lc;
};
vector<rng> rngs;
vi occ;

int lcs(int a, int b) {
    return E[rmq.range_minimum_query(H[a], H[b]).second];
}

int s;
bool cmp(rng a, rng b) {
    if(a.l / s != b.l / s) return a.l / s < b.l / s;
    return a.r < b.r;
}

vi vis;
int ans = 0;
void check(int a) {
    if(vis[a]) occ[w[a]]--, ans -= (occ[w[a]] == 0);
    else occ[w[a]]++, ans += (occ[w[a]] == 1);
    vis[a] ^= 1;
}

int main() {
    int n, q; cin >> n >> q;
    L.assign(2 * n, 0), E.assign(2 * n, 0), H.assign(2 * n, -1);
    w.assign(n, 0);
    children.assign(n, vi());

    for(auto &e: w) cin >> e;
    map<int, int> mp;
    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(mp.find(w[i]) == mp.end()) mp[w[i]] = ind++;
        w[i] = mp[w[i]];
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        children[a - 1].push_back(b - 1), children[b - 1].push_back(a - 1);
    }

    buildRMQ();
    rmq.init(L);

    l.assign(n + 10, 0), r.assign(n + 10, 0);
    dfss(0, -1);
    s = sqrt(oc.size()) + 1;

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        rng rn;
        if(H[a] >= H[b]) swap(a, b);

        if(lcs(a, b) == a) rn.l = l[a], rn.r = l[b];
        else rn.l = r[a], rn.r = l[b];
        rn.i = i;
        rn.lc = lcs(a, b);
        rngs.push_back(rn);
    }

    sort(rngs.begin(), rngs.end(), cmp);
    occ.assign(ind + 10, 0);
    vis.assign(n + 10, 0);
    vi anses(q, 0);

    int cl = -1, cr = -1;
    for(auto &e: rngs) {
        if(cl == -1 && cr == -1) for(int i = e.l; i <= e.r; i++)
                check(oc[i]), cl = e.l, cr = e.r;
        while(cl < e.l) check(oc[cl]), cl++;
        while(cl > e.l) cl--, check(oc[cl]);
        while(cr < e.r) cr++, check(oc[cr]);
        while(cr > e.r) check(oc[cr]), cr--;

        if(e.lc != oc[cl] && e.lc != oc[cr]) check(e.lc);
        anses[e.i] = ans;
        if(e.lc != oc[cl] && e.lc != oc[cr]) check(e.lc);
    }

    for(auto &e: anses) cout << e << endl;


    return 0;
}


