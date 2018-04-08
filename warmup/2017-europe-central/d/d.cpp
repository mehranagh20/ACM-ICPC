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

vvi grid;
viii f(int a, int b, int c) {
    viii tmp;
    bool ok = true;
    int i = 99, j = 99;
    int k = 0, r1 = 1 , r2  = 0;
    int s1 = 99, s2 = 9, k1 = 99, k2 = 99;
    int aa = a;
    while(a--) {
        if(k == 0) {
            grid[i + r2][j - r2] = 1;
            tmp.push_back(iii(i + r2, ii(j - r2, 0)));
            k = 1;
            s1 = i + r2, s2 = j - r2;
            r2++;
        }
        else {
            grid[i - r1][j + r1] = 1;
            tmp.push_back(iii(i - r1, ii(j + r1, 0)));
            k1 = i - r1, k2 = j + r1;
            k = 0;
            r1++;
        }
    }
    c -= b;
    b -= aa;
    k = 0;
    while(b--) {
        if(k == 0) {
            s2--;
            if(s2 < 0) continue;
            grid[s1][s2] = 1;
            tmp.push_back(iii(s1, ii(s2, 0)));
            k = 1;
        }
        else {
            k2++;
            if(k2 >= 200) continue;
            tmp.push_back(iii(k1, ii(k2, 0)));
            grid[k1][k2] = 1;
            k = 0;
        }
    }
    if(b > 0) ok = false;
    for(int rr = s1; rr >= k1; rr--)
        for(int ss = s2; ss <= k2; ss++) {
            if(c) {
                if (grid[rr][ss] == 0) {
                    grid[rr][ss] = 1;
                    c--;
                    tmp.push_back(iii(rr, ii(ss, 0)));
                }

            }
        }
    if(c > 0) ok = false;
    if(!ok) {
        tmp.clear();
        return tmp;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    int a, b, c;
    grid.assign(200, vi(200, 0));
    cin >> a >> b >> c;
    vi now = {a, b, c};
    sort(now.begin(), now.end());
    viii tmp = f(now[0], now[1], now[2]);
    for(auto &e: tmp) e.first -= 99, e.second.first -= 99;
    if(tmp.size() == 0) cout << -1 << endl;
    else {
        cout << tmp.size() << endl;
        if (a >= b && a >= c && b >= c) {
            for (auto &e: tmp) cout << e.second.first << " " << e.first << " " << e.second.second << endl;
        }
        else if (a >= b && a >= c && c >= b) {
            for (auto &e: tmp) cout << e.first << " " << e.second.first << " " << e.second.second << endl;
        }
        else if (b >= a && b >= c && a >= c) {
            for (auto &e: tmp) cout << e.second.first << " " << e.second.second << " " << e.first << endl;
        }
        else if (b >= a && b >= c && c >= a) {
            for (auto &e: tmp) cout << e.first << " " << e.second.second << " " << e.second.first << endl;
        }
        else if (c >= a && c >= b && a >= b) {
            for (auto &e: tmp) cout << e.second.second << " " << e.second.first << " " << e.first << endl;
        }
        else if (c >= a && c >= b && b >= a) {
            for (auto &e: tmp) cout << e.second.second << " " << e.first << " " << e.second.first << endl;
        }
    }



    return 0;
}
