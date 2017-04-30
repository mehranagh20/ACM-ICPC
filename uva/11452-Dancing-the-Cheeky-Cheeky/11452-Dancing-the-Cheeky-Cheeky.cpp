//In the name of God
#include<bits/stdc++.h>

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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))

string T, P; // T = text, P = pattern
int n, m; // size of text, size of pattern
vi b;

void kmpPreprocess() {
    b.assign(n + 1, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc; cin.get();
    while(tc--){
        getline(cin, P);
        n = m = P.size();
        kmpPreprocess();

        string ans;
        int ind = b[n - 1];
        while(ans.size() < 8)
            ans += P[++ind], P += ans.back();

        cout << ans + "...\n";
    }

    return 0;
}
