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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    int n; cin >> n;
    vi nums(n);
    int x = 1e9, y = 1;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(i)
            y = max(y, (int)abs(nums[i] - nums[i - 1]));
    }
    int j = (nums[0] - 1) % y + 1, i = (nums[0] - 1) / y + 1;
    int cur = nums[0];
    int pos = true;
    for(int k = 1; k < n; k++) {
        if(nums[k] == cur + y) i++;
        else if(nums[k] == cur - y) i--;
        else if(nums[k] == cur - 1) j--;
        else if(nums[k] == cur + 1) j++;
        else pos = false;

        if(i < 1 || j < 1 || j > y) pos = false;
        cur = nums[k];
    }

    if(!pos) cout << "NO" << endl;
    else cout << "YES" << endl << x << " " << y << endl;


    return 0;
}

