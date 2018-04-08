//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ull, ull > ii;
typedef pair<int, ii> iii;
typedef vector<ull> vi;
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
    ull n, a, b, c, d;
    ull tomm = 1e18;
//    cout << tomm << endl;
    while(cin >> n >> a >> b >> c >> d) {
        vi num(n + 1);
        for(int i = 1; i < num.size(); i++)
            cin >> num[i];
        vvi aa(a), bb(b), cc(c);
        for(auto &e: aa) {
            ull tmp; cin >> tmp;
            for (int i = 0; i < tmp; ++i) {
                ull tmp2; cin >> tmp2;
                e.push_back(tmp2);
            }
        }
        for(auto &e: bb) {
            ull tmp; cin >> tmp;
            for (int i = 0; i < tmp; ++i) {
                ull tmp2; cin >> tmp2;
                e.push_back(tmp2);
            }
        }
        for(auto &e: cc) {
            ull tmp; cin >> tmp;
            for (int i = 0; i < tmp; ++i) {
                ull tmp2; cin >> tmp2;
                e.push_back(tmp2);
            }
        }
        ull ans = 0;
        double ans2 = 0;
        bool tom = false;
        set<ii> stt;
        for (int l = 0; l < d; ++l) {
            ull tmp, tmpp; cin >> tmp >> tmpp;
            stt.insert(ii(tmp, tmpp));
            stt.insert(ii(tmpp, tmp));
        }
        for (int j = 0; j < a && !tom; ++j) {
            set<ull> st;
            ull now = 1;
            bool tom2 = false;
            for(auto &e: aa[j]) {
                now *= num[e], st.insert(e);
                if(now > tomm) tom2 = true;
            }
            for (int i = 0; i < b && !tom; ++i) {
                if(stt.find(ii(j + 1, i + a + 1)) != stt.end())
                    continue;
                ull now2 = 1;
                set<ull> st2 = st;
                bool tom3 = false;
                for(auto &e: bb[i])
                    if(st.find(e) == st.end())
                        now2 *= num[e], st2.insert(e);
                for (int k = 0; k < c && !tom; ++k) {
                    ull now3 = 1;
                    if(stt.find(ii(j + 1, a + b + 1 + k)) != stt.end()) continue;
                    if(stt.find(ii(i + a + 1, a + b + 1 + k)) != stt.end()) continue;
                    bool tom4 = false;
                    for(auto &e: cc[k])
                        if (st2.find(e) == st2.end())
                            now3 *= num[e];
                    ans += now * now2 * now3;
                    double tmp = now;
                    tmp *= now2;
                    tmp *= now3;
                    ans2 += tmp;
                }
            }
        }
        if(ans2 > 1e18 || ans > tomm) cout << "too many" << endl;
        else cout << ans << endl;

    }

    return 0;
}
