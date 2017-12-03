//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <queue>

#include <cstdio>
#include <cstring>
#include <complex>
#include <cmath>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef complex<ll> point;
typedef pair<int, point> pip;
ll vs(const point &a, const point &b) {//pointorovy sucin
    return imag(conj(a)*b);
}
ll ss(const point &a, const point &b) {//skalarny sucin
    return real(conj(a)*b);
}
bool priam(point a, point b, point c) {//je bod c na usecke ab?
    return vs(c-a, b-a) == 0 && ss(a-c, b-c) <= 0;
}
bool pret(point a, point b, point c, point d) {//pretinaju sa usecky ab a cd?
    if (priam(a, b, c)) return true;
    if (priam(a, b, d)) return true;
    if (priam(c, d, a)) return true;
    if (priam(c, d, b)) return true;
    return double(vs(c-a, b-a)) * vs(d-a, b-a) < 0 && double(vs(a-c, d-c)) * vs(b-c, d-c) < 0;
}

int main()
{
    int w, p;
    scanf("%d %d", &w, &p);
    vector<point> sou(w);
    rep(i,0,w)
    {
        int x, y; scanf("%d %d", &x, &y);
        sou[i] = point(x, y);
    }

    vector<pip> pipes(p);
    rep(i,0,p)
    {
        int s, x, y;
        scanf("%d %d %d", &s, &x, &y);
        pipes[i] = pip(s-1, point(x, y));
    }

    bool g[p][p];
    memset(g, 0x00, sizeof(g));
    rep(i,0,p) rep(j,0,i)
        if (pipes[i].first != pipes[j].first && pret(sou[pipes[i].first], pipes[i].second,
                                                     sou[pipes[j].first], pipes[j].second))
            g[i][j] = g[j][i] = true;

    vector<bool> seen(p, false);
    vector<bool> col(p, false);
    bool ok = true;
    rep(i,0,p) if (!seen[i])
    {
        queue<int> q;
        seen[i] = true;
        for (q.push(i); !q.empty(); q.pop())
        {
            int u = q.front();
            rep(j,0,p) if (g[u][j])
            {
                if (!seen[j])
                {
                    q.push(j);
                    col[j] = !col[u];
                    seen[j] = true;
                }
                else if (col[u] == col[j])
                    ok = false;
            }
        }
    }

    cout << (ok ? "possible" : "impossible") << endl;
}
