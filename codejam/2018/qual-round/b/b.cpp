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


int main() {
    int tc; scanf("%d", &tc);
    for(int i = 1; i <= tc; i++) {
        printf("Case #%d: ", i);
        int n; scanf("%d", &n);
        vi odd(n / 2), even(n / 2 + n % 2);
        int k = 0, k2 = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2)
                scanf("%lld", &odd[k2]), k2 += 1;
            else
                scanf("%lld", &even[k]), k += 1;
        }
        sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
        k = 0, k2 = 0;
        vi nums(n);
        for(int i = 0; i < n; i++) {
            if(i % 2) nums[i] = odd[k2], k2 += 1;
            else nums[i] = even[k], k += 1;
        }
        bool found = false;
        for(int i = 0; i < n - 1; i++) if(nums[i] > nums[i + 1]) {
                cout << i << endl;
                found = true;
                break;
            }
        if(!found) printf("OK\n");
    }

    return 0;
}