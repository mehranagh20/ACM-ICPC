#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

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
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define inf 100000000
#define eps 1e-9
#define pi acos(-1)

struct cmp {
    bool operator()(const string& a, const string& b) const {

        string a1 = a, b1 = b;
        //if(a.size() == b.size()) {
            if (a1.size() > 2) a1[2] = '$';
            if (b1.size() > 2) b1[2] = '$';
        //}
        return a1 < b1;
    }
};


int main() {
    ios::sync_with_stdio(0);
    string s, line;
    char c;
    int k = 1;
    bool end = false;

    while(true) {
        map<string, pair<int, string>, cmp> m;
        line.clear();

        while((c = cin.get()) && c != '#') {
            if (c != '\n') line += c;
            else line += ' ';
            if(c == EOF) {end = true; break;}
        }

        if(end)
            break;

        stringstream ss(line);

        while (ss >> s) {
            s = s.substr(0, 5);

            auto it = m.find(s);
            if(it == m.end())
                m[s] = make_pair(1, s);
            else{
                auto &p = it->second;
                p.first++, p.second = s;
            }

        }

        cout << "Set #" << k++ << ":\n";
        for(auto it: m)
            cout << it.second.second << ' ' << it.second.first << endl;
        cout << endl;

    }

    return 0;
}
