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

int main() {
    ios::sync_with_stdio(0);
    // cout << tolower(1) << endl;
    int a; string s;
    set<char> sss;
    cin >> a >> s;
    for(auto &c: s) sss.insert(c);
    for(int i = 0; i < a; i++) {
        string ss; cin >> ss;
        bool ok = true;
        set<char> tmp;
        for(auto &e: ss) tmp.insert(e);
        vi aa, bb;
        for(auto &e: tmp) aa.push_back(e);
        for(auto &ee: sss) bb.push_back(ee);
        if(aa != bb) {
            cout << "No" << endl;
        }
        else
        cout << "Yes" << endl;

    }


    return 0;
}
