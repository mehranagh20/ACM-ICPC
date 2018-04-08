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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        vi num, num2;
        set<int> st;
        int x = 0;
        map<int, int> mp;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if(tmp == 0) x++;
            else if(tmp > 0) mp[tmp]++;
            else {
                if(mp[-tmp] > 0) mp[-tmp]--;
                else if(x) {
                    x--;
                    num.push_back(tmp);
                }
                else ok = false;
            }
        }
        if(ok) {
            cout << "Yes" << endl;
            if(num.size()) {
                cout << -num[0];
                for (int i = 1; i < num.size(); i++) cout << " " << -num[i];
                while(x--) cout << " 1" << endl;
            }
            if(x > 0) {
                cout << '1';
                x--;
                while(x--) cout << " 1" << endl;
            }
            cout << endl;
        }
        else cout << "No" << endl;
    }


    return 0;
}
