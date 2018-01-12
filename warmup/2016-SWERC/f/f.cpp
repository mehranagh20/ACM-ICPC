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
typedef vector<ull> vi;
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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vi arr, t, lazy; // arr is numbers to build seg tree with, if its size is 'n' then t and lazy size should be 4 * n (2 * n)

void build(int node, int a, int b)
{
    if(a>b) return;
    if (a==b)
    {
        t[node]=arr[a];
        return;
    }

    build(node*2, a, (a+b)/2);
    build(node*2+1,(a+b)/2+1,b);

    t[node]=t[node*2]+t[node*2+1];
}

ull query(int node, int a, int b, int i, int j)
{
    if(a>b||a>j||b<i) return 0;
    if (lazy[node] !=0 )
    {
        t[node]+=lazy[node]*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if (a>=i && b<=j) return t[node];

    ull q1=query(node*2, a, (a+b)/2, i, j);
    ull q2=query(node*2+1, (a+b)/2+1, b, i, j);

    return q1+q2;
}

void update(int node, int a, int b, int i, int j, int inc)
{
    if(a>b) return;
    if (lazy[node]!=0)
    {
        t[node]+=lazy[node]*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(a>b||a>j||b<i) return;

    if (a>=i && b<=j)
    {
        t[node]+=inc*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]+=inc;
            lazy[node*2+1]+=inc;
        }
        return;
    }

    update(node*2, a, (a+b)/2, i, j, inc);
    update(node*2+1, (a+b)/2+1, b,i, j, inc);
    t[node] = t[node*2] + t[node*2+1];
}
int n, mx;
vi rnk, cost, ans;
int solve(vvi &graph, int i) {
    ull r = rnk[i], c = cost[i];
    ull bef = query(1, 0, mx - 1, r, r);
    for(auto &e: graph[i])
        solve(graph, e);
    ull now = query(1, 0, mx - 1, r, r);
    ans[i] = now - bef;
    update(1, 0, mx - 1, r + 1, mx - 1, c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    mx = 1e5 + 10;
    arr.assign(mx, 0), lazy.assign(4 * mx, 0), t.assign(4 * mx, 0);
    build(1, 0, mx - 1);
    cin >> n;
    vvi graph(n);
    rnk.assign(n, 0), cost.assign(n, 0);
    int root;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        rnk[i] = b, cost[i] = c;
        a--;
        if(a < 0) root = i;
        else graph[a].push_back(i);
    }
    ans.assign(n, 0);
    solve(graph, root);
    for(auto &e: ans) cout << e << endl;

    return 0;
} 
