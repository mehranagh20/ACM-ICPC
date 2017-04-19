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


int f(int x){
    return (x * x / 100) % 10000;
}

ii floydCycleFinding(int x0) { // function int f(int x) is defined earlier
    int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int mu = 0;
    hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    int lambda = 1;
    hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lambda++;
    }
    return ii(mu, lambda); // mu is the start of circle, lambda is lengh of circle
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n){
        ii ans = floydCycleFinding(n);
        //while(n != ans.first)
        //    ans.second++, n = f(n);
        cout << ans.second + ans.first << endl;
    }


    return 0;
}
