//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
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


int main() {
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        int n, k, d; cin >> n >> k >> d;
        vd drinks(d), caces(k);
        double all = 0;
        for(int i = 0; i < k; i++) {
            cin >> caces[i];
            all += caces[i];
        }
        for(int i = 0; i < d; i++) {
            cin >> drinks[i];
            all += drinks[i];
        }
        for(int i = d + k; i < n; i++) {
            double tmp; cin >> tmp;
            all += tmp;
        }
        all /= n;
        sort(caces.begin(), caces.end());
        sort(drinks.begin(), drinks.end());
        double dP = drinks[0], cP = caces[0];
        for(int i = 1; i < drinks.size(); i++) if(fabs(all - dP) - fabs(all - drinks[i]) > eps)
                dP = drinks[i];
        for(int i = 1; i < caces.size(); i++) if(fabs(all - cP) - fabs(all - caces[i]) > eps)
                cP = caces[i];
        cout << "Case #" << i + 1 << ": " << (int)cP << " " << (int)dP << endl;
    }

    return 0;
}