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

map<char, int> ci = {{'V', 0}, {'U', 1}, {'C', 2}, {'D', 3}};
map<int, char> ic = {{0, 'V'}, {1, 'U'}, {2, 'C'}, {3, 'D'}};

int convertToBaseTen(string a) {
    int num = 0, p = 1;
    for(int i = a.size() - 1; i >= 0; i--) num += p * ci[a[i]], p *= 4;
    return num;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    cout << "COWCULATIONS OUTPUT\n";
    while(tc--) {
        string str1, str2, tmp; cin >> str1 >> str2;
        int a = convertToBaseTen(str1), b = convertToBaseTen(str2);
        for(int i = 0; i < 3; i++) {
            cin >> tmp;
            if(tmp == "A") b = a + b;
            if(tmp == "R") b /= 4;
            if(tmp == "L") b *= 4;
        }
        cin >> str1;
        int result = convertToBaseTen(str1);
        if(result == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    cout << "END OF OUTPUT\n";

    return 0;
}