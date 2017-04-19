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
    set<string> mp;
    string str;
    vs ans;
    int k = -1;
    while(cin >> str && str != "#") mp.insert(str);
    cin.get();
    getline(cin, str);
    for(int i = 0; i < 26; i++) {
        int num = 0;
        string cur = "";
        vs now;
        for(auto &c : str) {
            c++;
            if(c == 'Z' + 1) c = ' ';
            if(c == ' ' + 1) c = 'A';
            if(c == ' ') {
                if(mp.find(cur) != mp.end())
                num++;
                now.push_back(cur), cur = "";
            }
            else cur += c;
        }
        if(num > k) ans = now, k = num;
    }
    int sz = 0;
    for(auto &e : ans) {
        if(sz + e.size() > 60) cout << endl, sz = 0;
        if(sz) cout << " ", sz++;
        cout << e;
        sz += e.size();
    }
    cout << endl;


    return 0;
}
