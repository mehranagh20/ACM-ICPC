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

string T, P; // T = text, P = pattern
int n, m, ans; // size of text, size of pattern
vi b;

void kmpPreprocess() {
    b.assign(n, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++;
        if (j == m) {
            //printf("P is found at index %d in T\n", i - j);
            ans += 1;
            j = b[j]; // prepare j for the next possible match
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> P && P != ".") {
        T = P + P;
        m = P.size(), n = T.size();
        ans = -1;
        kmpPreprocess(); kmpSearch();
        cout << ans << endl;
    }


    return 0;
}
