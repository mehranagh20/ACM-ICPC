//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

string step(string str) {
    bitset<16>(str.substr(0, 16)), bitset<16>(str.substr(16, 16));

}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string str; cin.ignore(2);
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        double all = 0;
        int a, b, c, d; cin >> a >> b;
        cin.ignore();
        while(getline(cin, str) && !str.empty()) {
            stringstream ss(str);
            ss >> a >> b >> c >> d;
            all += 2 * sqrt(pow(c - a, 2) + pow(d - b, 2));
        }
        all = all / 20000;
        int h = floor(all);
        all -= h;
        all *= 60;
        int min = floor(all);
        all -= min;
        if(all > .5) min++;
        if(min >= 60) h++, min -= 60;
        cout << h << ":" << setw(2) << setfill('0') << min << endl;


    }


    return 0;
}