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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    string a, b;
    while(getline(cin, a) && getline(cin, b) && !cin.eof()) {
        map<char, int> mpa, mpb;
        for(auto &e : a) mpa[e]++;
        for(auto &e : b) mpb[e]++;
        vector<char> vc;
        for(auto it = mpa.begin(); it != mpa.end(); it++) if(mpb.find(it->first) != mpb.end())
            for(int i = 0; i < min(it->second, mpb[it->first]); i++) vc.push_back(it->first);
        sort(vc.begin(), vc.end());
        for(auto &e : vc) cout << e;
        cout << endl;
    }


    return 0;
}
