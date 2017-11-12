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
vector<pair<char, string>> v;
string en;

bool isok(int id, string str) {
    if(id + str.size() > en.size()) return false;
    for(int i = 0; i < str.size(); i++) if(en[i + id] != str[i]) return false;
    return true;
}

int printed;
void back(string &str, int ind) {
    if(printed >= 100) return;
    if(ind == en.size()) {
        printed++;
        cout << str << endl;
    }
    else {
        for(auto &e: v) {
            // if(en[ind] == '0') back(str, ind + 1);
            // if(ind + e.second.size() >= en.size()) continue;
            if(en[ind] == '0' && isok(ind + 1, e.second)) {
                str.push_back(e.first);
                back(str, ind + e.second.size() + 1);
                str.pop_back();
            }
            if(isok(ind, e.second)) {
                str.push_back(e.first);
                back(str, ind + e.second.size());
                str.pop_back();
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 1;
    while(cin >> n && n) {
        v.clear();
        for(int i = 0; i < n; i++) {
            char a; string b;
            cin >> a >> b;
            v.push_back(pair<char, string>(a, b));
        }
        cin >> en;
        sort(v.begin(), v.end());
        printed = 0;
        string tmp;
        cout << "Case #" << tc++ << endl;
        back(tmp, 0);
        cout << endl;
    }


    return 0;
}
