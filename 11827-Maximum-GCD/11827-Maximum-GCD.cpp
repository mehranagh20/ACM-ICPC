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

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    cin.get();
    while(n--) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        vi nums;
        int tmp;
        ll mx = 0;
        while(ss >> tmp) nums.push_back(tmp);
        for(int i = 0; i < nums.size(); i++) for(int j = i + 1; j < nums.size(); j++)
            mx = max(mx, gcd(nums[i], nums[j]));
        cout << mx << endl;
    }

    return 0;
}
