    //In The Name Of God
    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    typedef vector<string> vs;
    typedef pair<ll, ll> ii;
    typedef pair<ii, int> iii;
    typedef pair<double, double> dd;
    typedef pair<dd, double> ddd;
    typedef vector<int> vi;
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
        ios::sync_with_stdio(0);
        int n; cin >> n;
        vs ss(n);
        ll s = 0, h = 0;
        vii nums(n);
        vector<pair<double, int>> cc;
        for (int i = 0; i < n; ++i) {
            cin >> ss[i];
            for(auto &e: ss[i])
                if(e == 'h') h++, nums[i].second++;
                else s++, nums[i].first++;
            cc.push_back(make_pair((double)nums[i].second / nums[i].first, i));
        }
        sort(cc.begin(), cc.end());
        ll anss = 0;
        for(int i = n - 1; i >= 0; i--) {
            ll ff = 0, cu = cc[i].second;
            for(auto &e: ss[cu]) {
                if(e == 's') ff++;
                else anss += ff;
            }
            s -= nums[cu].first;
            anss += s * nums[cu].second;
        }
        cout << anss << endl;


        return 0;
    }