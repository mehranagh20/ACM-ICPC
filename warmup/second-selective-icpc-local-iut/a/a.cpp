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
    string str; cin >> str;
    string n = str.substr(0, str.size() / 2), nn = str.substr(str.size() / 2, str.size());
    int sum = 0, s2 = 0;
    for(auto &e: n) sum += e - 'A';
    for(auto &e: nn) s2 += e - 'A';

    for(auto &e: n) e = (((e - 'A') + sum) % 26) + 'A';
    for(auto &e: nn) e = (((e - 'A') + s2) % 26) + 'A';
    for(int i = 0; i < str.size() / 2; i++)
        n[i] = (((n[i] - 'A') + (nn[i] - 'A')) % 26) + 'A';
    cout << n << endl;


    return 0;
}
