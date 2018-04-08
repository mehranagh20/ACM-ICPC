//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

vi nums;
vi tmp;

ll merge_count(int a, int b) {
    ll k = a, now = 0;
    ll i = a, j = (a + b) / 2 + 1, mid = (a + b) / 2;
    while(i <= (a + b) / 2 && j <= b) {
        if(nums[i] < nums[j]) tmp[k] = nums[i++];
        else tmp[k] = nums[j++], now += mid - i + 1;
        k++;
    }
    while(i <= (a + b) / 2) { tmp[k++] = nums[i++];}
    while(j <= b) { tmp[k++] = nums[j++];}

    for(int i = a; i <= b; i++) nums[i] = tmp[i];
    return now;
}

ll count(int a, int b) {
    if(b - a + 1 <= 1) return 0;
    ll x = count(a, (a + b) / 2) + count((a + b) / 2 + 1, b);
    return x + merge_count(a, b);
}

ll solve(vi &a, vi &b) {
    for(int i = 0; i < a.size(); i++) tmp[a[i] - 1] = i;
    for(int i = 0; i < a.size(); i++) nums[i] = tmp[b[i] - 1];
    ll x = count(0, a.size() - 1);
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    ll n;
    nums.assign(200000010, 0);
    tmp.assign(200000010, 0);
    while(cin >> n) {
        vi a(n), b(n), c(n);
        for(auto &e: a) cin >> e;
        for(auto &e: b) cin >> e;
        for(auto &e: c) cin >> e;
        ll x = solve(a, b) + solve(a, c) + solve(b, c);
        cout << (n * (n - 1)) / 2 - x / 2 << endl;


    }


    return 0;
}
