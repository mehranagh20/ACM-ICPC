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
    map<char, int> m;
    m['A'] = m['B'] = m['C'] = 2;
    m['D'] = m['E'] = m['F'] = 3;
    m['G'] = m['H'] = m['I'] = 4;
    m['J'] = m['K'] = m['L'] = 5;
    m['M'] = m['N'] = m['O'] = 6;
    m['P'] = m['Q'] = m['R'] = m['S'] = 7;
    m['T'] = m['U'] = m['V'] = 8;
    m['W'] = m['X'] = m['Y'] = m['Z'] = 9;

    vs v(10, "");
    for(int i = 'A'; i <= 'Z'; i++){
        v[m[i]].push_back(i);
    }

    int tc;
    cin >> tc;
    while(tc--){
        int p, w, ans = 0;
        cin >> p >> w;

        string s;
        //cin.ignore();
        getline(cin, s);
        getline(cin, s);
        int k = 0, prev = 0;

        for(auto& c: s){
            if(c == ' '){
                ans += p;
                k++;
                prev = 0;
                continue;
            }

            if(k && prev == m[c])
                ans += w;

            int ind = prev = m[c];
            int num = v[ind].find(c) + 1;
            ans += p * num;
        }

        cout << ans << endl;
    }


    return 0;
}
