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
    string str;
    while(cin >> str) {
        sort(str.begin(), str.end());
        string sec;
        for(int i = str.size() - 1; i >= 0; i--) sec += str[i];
        int i = str.size() - 1;
        while(sec[i] == '0') i--;
        string first; first += sec[i];
        for(int j = i + 1; j < str.size(); j++) first += '0';
        i--;
        for(; i >= 0; i--) first += sec[i];

        ll x = stoll(sec) - stoll(first);
        cout << stoll(sec) << " - " << stoll(first) << " = " << x << " = " << 9 << " * " << x / 9 << endl;
    }


    return 0;
}
