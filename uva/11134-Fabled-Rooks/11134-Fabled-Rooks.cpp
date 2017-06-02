//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
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

bool comp(iii a, iii b) {
    return a.first.first < b.first.first;
}

class mycompare {
public:
    bool operator() (iii a, iii b) {
        return a.first.second > b.first.second;
    }
};

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        viii xs(n), ys(n);
        vii ans(n);
        for(int i = 0; i < n; i++) {
            cin >> xs[i].first.first >> ys[i].first.first >> xs[i].first.second >> ys[i].first.second;
            xs[i].second = ys[i].second = i;
        }
        sort(xs.begin(), xs.end(), comp);
        sort(ys.begin(), ys.end(), comp);
        bool impossible = false;
        priority_queue<iii, viii, mycompare> xp, yp;
        int xl = 0, yl = 0;
        for(int i = 1; i <= n; i++) {
            while(xl < n) {
                if(xs[xl].first.first <= i) xp.push(xs[xl]);
                else break;
                xl++;
            }
            while(yl < n) {
                if(ys[yl].first.first <= i) yp.push(ys[yl]);
                else break;
                yl++;
            }
            if(xp.empty() || yp.empty()) {
                impossible = true;
                break;
            }
            iii tmp = xp.top(); xp.pop();
            if(tmp.first.second < i) impossible = true;
            ans[tmp.second].first = i;
            tmp = yp.top(); yp.pop();
            if(tmp.first.second < i) impossible = true;
            ans[tmp.second].second = i;
        }
        if(impossible) cout << "IMPOSSIBLE" << endl;
        else
            for(auto &e: ans) cout << e.first << " " << e.second << endl;
    }


    return 0;
}
