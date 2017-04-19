//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, char> ss;
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

vvii table;

void wunsnch(string a, string b) {
    int n = a.size(), m = b.size();
    table[0][0].second = -1, table[0][0].first = 0;
    for(int i = 1; i <= n; i++) table[i][0].first = i * 1, table[i][0].second = 1;
    for(int i = 1; i <= m; i++) table[0][i].first = i * 1, table[0][i].second = 2;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        int &x = table[i][j].first, &y = table[i][j].second;
        x = table[i - 1][j - 1].first + (a[i - 1] == b[j - 1] ? 0 : 1), y = 0; // a[i - 1] because it is 0 base
        if(x > table[i - 1][j].first + 1) x = table[i - 1][j].first + 1, y = 1; // delete
        if(x > table[i][j - 1].first + 1) x = table[i][j - 1].first + 1, y = 2; // insert
    }

}

void op(string aa, string bb) {
    int a = aa.size(), b = bb.size(), num = 1;
    vii trans = {{-1, -1}, {-1, 0}, {0, -1}};
    vs commands;
    vector<pair<int, char>> arg;
    while(table[a][b].second != -1) {
        int tr = table[a][b].second;
        if(tr == 0) {
            if(aa[a - 1] != bb[b - 1])
                commands.push_back("Replace"), arg.push_back(ss(a, bb[b - 1]));
        }
        else if(tr == 1)
            commands.push_back("Delete"), arg.push_back(ss(a, ' '));
        else commands.push_back("Insert"), arg.push_back(ss(b, bb[b - 1]));
        a += trans[tr].first, b += trans[tr].second;
    }
    int add = 0;
    for(int i = commands.size() - 1; i >= 0; i--) {
        cout << num++ << " ";
        string com = commands[i];
        if(com == "Replace") cout << com << " " << arg[i].first + add << "," << arg[i].second << endl;
        else if(com == "Delete") cout << com << " " << arg[i].first + add << endl, add--;
        else cout << com << " " << arg[i].first << "," << arg[i].second << endl, add++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    string a, b;
    int tc = 0;
    while(getline(cin, a) && cin && getline(cin, b) && cin) {
        if(tc++) cout << endl;
        table.assign(a.size() + 10, vii(b.size() + 10, ii(inf, 0)));
        wunsnch(a, b);
        cout << table[a.size()][b.size()].first << endl;

        // cout << a << " " << b << endl;
        // for(int i = 0; i <= a.size(); i++) {
        //     for(int j = 0; j <= b.size(); j++) cout << table[i][j].first << " ";
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i = 0; i <= a.size(); i++) {
        //     for(int j = 0; j <= b.size(); j++) cout << table[i][j].second << " ";
        //     cout << endl;
        // }
        // cout << endl << endl;
        op(a, b);
    }

    return 0;
}
