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
typedef vector<ll> vi;
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

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000 + 1
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

vi nums, f;
int n;

void upd(int pos, int d){
	for(; pos < n; pos |= pos + 1)
		f[pos] += d;
}

int get(int pos){
	int res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

int main() {
    ios::sync_with_stdio(0);
	cin >> n;
	nums.assign(n, 0), f.assign(n, 0);
	vvi stoep(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i]; nums[i]--;
		if(nums[i] < n)
			stoep[nums[i]].push_back(i);
	}
	for(int i = 0; i < n; i++) upd(i, 1);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += get(min(nums[i], (long long)n - 1));
        for(auto &e: stoep[i])
			upd(e, -1);
	}

	for(int i = 0; i < n; i++) if(nums[i] >= i)
			ans--;

	cout << ans / 2 << endl;



    return 0;
}