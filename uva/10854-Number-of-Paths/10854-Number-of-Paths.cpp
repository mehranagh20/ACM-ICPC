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

int cur;
vs commands;

int solve_if();

int solve_else() {
    int now = 1;
    while(commands[cur] == "S") cur++;
    while(commands[cur] == "IF") {
        cur++;
        now *= solve_if();
    }
    while(commands[cur] == "S") cur++;
    cur++;
    return now;
}

int solve_if() {
    int now = 1;
    while(commands[cur] == "S") cur++;
    while(commands[cur] == "IF") {
        cur++;
        now *= solve_if();
    }
    while(commands[cur] == "S") cur++;
    cur++;
    now += solve_else();
    while(cur < commands.size() && commands[cur] == "S") cur++;

    return now;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        commands.clear();
        string str;
        while(cin >> str && str != "ENDPROGRAM") commands.push_back(str);
        cur = 0;
        int ans = 1;
        while(cur != commands.size()) {
            if(commands[cur] == "S") {
                cur++;
                continue;
            }
            cur++;
            ans *= solve_if();
        }
        cout << (ans == 0 ? 1 : ans) << endl;
    }



    return 0;
}
