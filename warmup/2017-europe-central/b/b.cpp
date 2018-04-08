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

int w, h;

bool check(int a,int b,int c){
    int ww, hh;

    ww = max(b + 2 * c, 2 * c + 2 * a);
    hh = min(b + 2 * c, 2 * c + 2 * a);
    if(ww <= w && hh <= h) return true;

    ww = max(c + 2 * b, 2 * c + 2 * a);
    hh = min(c + 2 * b, 2 * c + 2 * a);
    if(ww <= w && hh <= h) return true;

    ww = max(a + b + c, 2 * c + 2 * a);
    hh = min(a + b + c, 2 * c + 2 * a);
    if(ww <= w && hh <= h) return true;


    ww = max(b + 2 * c, b + c + 2 * a);
    hh = min(b + 2 * c, b + c + 2 * a);
    if(ww <= w && hh <= h) return true;

    ww = max(a + b + c, 2 * b + a + c);
    hh = min(a + b + c, 2 * b + a + c);
    if(ww <= w && hh <= h) return true;

    ww = max(3 * b + a + c, c + a);
    hh = min(3 * b + a + c, c + a);
    if(ww <= w && hh <= h) return true;

    ww = max(2 * a + b, 2 * c + a + b);
    hh = min(2 * a + b, 2 * c + a + b);
    if(ww <= w && hh <= h) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int x, y, z;
    while(cin >> x >> y >> z >> w >> h){

        int tm = min(w, h), tm2 = max(w, h);
        w = tm2, h = tm;


        vvi num;
        num.push_back({x, y, z});
        num.push_back({x, z, y});
        num.push_back({y, x, z});
        num.push_back({y, z, x});
        num.push_back({z, y, x});
        num.push_back({z, x, y});

        bool ok = false;
        for(auto e: num)
            ok |= check(e[0], e[1], e[2]);

        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}
