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
    vvi f(110, vi(300));
    map<char, int> mp;
    mp['A'] = mp['B'] = mp['C'] = 2;
    mp['D'] = mp['E'] = mp['F'] = 3;
    mp['G'] = mp['H'] = mp['I'] = 4;
    mp['J'] = mp['K'] = mp['L'] = 5;
    mp['M'] = mp['N'] = mp['O'] = 6;
    mp['P'] = mp['Q'] = mp['R'] = mp['S'] = 7;
    mp['T'] = mp['U'] = mp['V'] = 8;
    mp['W'] = mp['X'] = mp['Y'] = mp['Z'] = 9;
    vs s = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

    for(int i = 0; i < 110; i++) {
        for(char c = 'A'; c <= 'Z'; c++) {
            int pos = mp[c];
            int num = pos + i;
            int sz = num % s[pos].size();
            f[i][s[pos][sz]] = c;
        }
    }
    string str;
    while(cin >> str && str != "#") {
        string ans;
        for(int i = 0; i < str.size(); i++) {
            bool isUp = isupper(str[i]);
            ans += f[i][toupper(str[i])];
            if(!isUp) ans.back() = tolower(ans.back());
        }
        cout << ans << endl;
    }


    return 0;
}
