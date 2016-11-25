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
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

#define mx 2001000

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool comp(ii a, ii b) {
    return a.first * b.second < b.first * a.second;
}

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    while(cin >> n >> k) {
        vii seq;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++)
                if(gcd(i, j) == 1) seq.push_back(ii(j, i));
        sort(seq.begin(), seq.end(), comp);
        cout << seq[k - 1].first << "/" << seq[k - 1].second << endl;
    }

    return 0;
}