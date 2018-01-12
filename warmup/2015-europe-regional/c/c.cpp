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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

bool areParallel(ddd l1, ddd l2) {
    return (fabs(l1.first.first - l2.first.first) < eps) &&
           (fabs(l1.first.second-l2.first.second) < eps);
}
    void pointsToLine(dd p1, dd p2, ddd &l) {
        double &a = l.first.first, &b = l.first.second, &c = l.second;
        double &x1 = p1.first, &y1 = p1.second, &x2 = p2.first;

        if (fabs(x1 - x2) < eps) // vertical line is fine
            a = 1.0, b = 0.0, c = -x1;

        else {
            a = -(y1 - p2.second) / (x1 - x2);
            b = 1.0; // IMPORTANT: we fix the value of b to 1.0
            c = -(a * x1) - y1;
        }
    }


bool lineIntersect(ddd l1, ddd l2, dd &p) {
    double &a1 = l1.first.first, &b1 = l1.first.second, &c1 = l1.second;
    double &a2 = l2.first.first, &b2 = l2.first.second, &c2 = l2.second;
    double &x = p.first, &y = p.second;
    if (areParallel(l1, l2)) {
        return false;

    } // no intersection

    // solve system of 2 linear algebraic equations with 2 unknowns
    x = (b2 * c1 - b1 * c2) / (a2 * b1 - a1 * b2);

    // special case: test for vertical line to avoid division by zero
    y = -(fabs(b1) > eps ? a1 * x + c1 : a2 * x + c2);
    return true;
}

double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

bool segIntersect(dd a, dd b, dd m, dd n, dd &p){
    ddd l1; pointsToLine(a, b, l1);
    ddd l2; pointsToLine(m, n, l2);
    for(auto &e: {a, b}) for(auto &ee: {n, m})
            if(e == ee) {
                p = e;
                return true;
            }
    if(lineIntersect(l1, l2, p))
        return (fabs(dist(a, b) - (dist(a, p) + dist(p, b))) < eps) && (fabs(dist(m, n) - (dist(m, p) + dist(p, n))) < eps);
    return false;
}

struct point {
    ll x, y;
    point(ll x=0, ll y=0): x(x), y(y) {}
    bool operator==(point p) { return x == p.x && y == p.y; }
    point operator-(point p) { return point(x-p.x, y-p.y); }
    ll cross(point p) { return x*p.y - y*p.x; }
};

bool isect(dd p1, dd p2, dd q1, dd q2) {
    point P1(p1.first, p1.second), P2(p2.first, p2.second), Q1(q1.first, q1.second), Q2(q2.first, q2.second);
    ll d = (Q2-Q1).cross(P2-P1);
    if (!d) return P2 == Q2;
    double t = 1.0*(P2-P1).cross(Q1-P1)/d;
    double s = 1.0*(Q2-Q1).cross(Q1-P1)/d;
    return 0 <= t && t <= 1 && 0 <= s && s <= 1;
}

bool isbi(int s, vvi &AdjList, vi &color) {
    queue<int> q; q.push(s);
    color[s] = 0;
    bool isBipartite = true;
    while (!q.empty() & isBipartite) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int) AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if (color[v] == inf) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                isBipartite = false;
                break;
            }
        }
    }
    return isBipartite;
}

int main() {
    ios::sync_with_stdio(0);
    int n, p;
    while(cin >> n >> p) {
        vii w(n);
        for(auto &e: w) cin >> e.first >> e.second;
        vvi graph(p);
        viii pp(p);
        for(int i = 0; i < p; i++) {
            cin >> pp[i].first >> pp[i].second.first >> pp[i].second.second;
            for(int j = 0; j < i; j++) if(pp[i].first != pp[j].first) {
                    dd tmp;
                    if(segIntersect(w[pp[i].first - 1], pp[i].second, w[pp[j].first - 1], pp[j].second, tmp))
                        graph[i].push_back(j), graph[j].push_back(i);
                }
        }
        bool ok = true;
        vi color(p, inf);
        for(int i = 0; i < p; i++) if(color[i] == inf)
                if(!isbi(i, graph, color)) ok = false;
        if(ok) cout << "possible" << endl;
        else cout << "impossible" << endl;
    }


    return 0;
}
