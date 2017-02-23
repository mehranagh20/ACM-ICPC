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

int n, m, ans; // size of text, size of pattern
vi b;

void kmpPreprocess(string &P) {
    b.assign(n + 1, -1);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch(string &P, string &T) {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++;
        if(i == n) ans = j;
        // if (j == m) {
        //     //printf("P is found at index %d in T\n", i - j);
        //     j = b[j]; // prepare j for the next possible match
        // }
    }
}

int main() {
    ios::sync_with_stdio(0);
    string T;
    while(cin >> T) {
        string P = "";
        for(int i = T.size() - 1; i >= 0; i--) P += T[i];
        n = m = T.size();
        kmpPreprocess(P); kmpSearch(P, T);
        for(int i = ans; i < n; i++) T += P[i];
        cout << T << endl;
    }


    return 0;
}
