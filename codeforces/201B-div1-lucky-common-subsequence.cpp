//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vector<vector<vector<string>>> memo;
string t1, t2, p; // T = text, P = pattern
vi b;

void kmpPreprocess() {
    b.assign(max(t1.size(), t2.size()) + 1, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < p.size()) {
        while (j >= 0 && p[i] != p[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void fmax(string &ans, string cur) {
    if(cur == "-1") return;
    if(ans == "-1") ans = cur;
    if(cur.size() > ans.size()) ans = cur;
}

string solve(int i, int j, int k) {
    if(k == p.size()) return "-1";
    if(i == t1.size() || j == t2.size()) return "";
    string &cur = memo[i][j][k];
    if(cur != "-2") return cur;
    cur = "";
    if(t1[i] == t2[j]) {
        int r = k;
        while(r >= 0 && t1[i] != p[r]) r = b[r];
        string c = solve(i + 1, j + 1, r + 1);
        if(c != "-1")
            cur = c + t1[i];
    }
    fmax(cur, solve(i + 1, j, k));
    fmax(cur, solve(i, j + 1, k));

    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> t1 >> t2 >> p;
    kmpPreprocess();

    memo.assign(t1.size() + 10, vector<vector<string>>(t2.size() + 10, vs(p.size() + 10, "-2")));
    string ans = solve(0, 0, 0);
    if(ans == "" || ans == "-1") cout << 0 << endl;
    else {
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }




    return 0;
}

