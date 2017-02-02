//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<unsigned int> vi;
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
int n, MOD = 10;
vvi iden;

void matMul(vvi &a, vvi &b) {            // O(n^3), but O(1) as n = 2
  vvi ans(n, vi(n, 0)); int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      for (ans[i][j] = k = 0; k < n; k++) {
        ans[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
        ans[i][j] %= MOD;             // modulo arithmetic is used here
      }
  a = ans;
}

void matPow(vvi &base, int p) {  // O(n^3 log p), but O(log p) as n = 2
  vvi ans(n, vi(n)); int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      ans[i][j] = (i == j);                  // prepare identity vvi
  while (p) {       // iterative version of Divide & Conquer exponentiation
    if (p & 1)                    // check if p is odd (the last bit is on)
      matMul(ans, base);                                // update ans
    matMul(base, base);                           // square the base
    p >>= 1;                                               // divide p by 2
  }
  base = ans;
}

void matSum(vvi &a, vvi &b) {
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        a[i][j] = (a[i][j] + b[i][j]) % MOD;
}

void ans(vvi &a, int p) {
    if(p == 0 || p == 1) return;
    vvi apow = a, l1 = a, l2 = a;
    int maxn = log2(p);
    for (int i = 0; i < maxn; ++i) {
        vvi tmp = apow; matSum(tmp, iden);
        matMul(a, tmp);
        matPow(apow, 2);
    }
    int cur = p - pow(2, maxn);
    if(!cur) return;
    matPow(l1, cur); matMul(a, l1); ans(l2, cur);
    matSum(a, l2);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    int k;
    iden.assign(41, vi(41, 0));
    for(int i = 0; i < 41; i++) iden[i][i] = 1;
    while(cin >> n >> k && n) {
        vvi mat(n, vi(n));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> mat[i][j];
        ans(mat, k);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j) cout << " ";
                cout << mat[i][j] % MOD;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
