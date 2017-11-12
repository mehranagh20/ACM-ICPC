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
typedef pair<string, int> psi;
typedef pair<psi, string> psis;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int dup = 0;
        map<string, set<psis>> mp;
        string var, op, on, tmp;
        int num;
        for(int i = 0; i < n; i++) {
            cin >> var >> var >> op >> num >> on >> on >> on >> tmp;
            if(mp[on].find(psis(psi(var, num), op)) == mp[on].end())
                mp[on].insert(psis(psi(var, num), op));
            else dup++;
        }
        int ans = 0;
        for(auto itt = mp.begin(); itt != mp.end(); itt++) {
            int cur_ans = 0;
            vi inffs;
            set<psis> now = itt->second;
            auto it = now.begin();
            while(it != now.end()) {
                auto it2 = it;
                while (it->first.first == it2->first.first) it2++;
                int big = inf, sm = -inf;
                for(auto k = it; k != it2; k++) {
//                    cerr << k->first.second << " " << k->second << endl;
                    if(k->second == ">") big = min(big, k->first.second);
                    if(k->second == "<") sm = max(sm, k->first.second);
                }
                int bigsm = 0, eq = 0, deq = 0;
                for(auto k = it; k != it2; k++) {
                    if(k->second == "=") {
                        if(k->first.second > big) deq++;
                        else if(k->first.second < sm) deq++;
                        else eq++;
                    }
                    else {
                        if(k->second == ">" && k->first.second != big) bigsm++;
                        if(k->second == "<" && k->first.second != sm) bigsm++;
                    }
                }
                cur_ans += bigsm + deq;
                big++, sm--;
                if(big - sm <= 1 || big - sm - 1 == eq) inffs.push_back(eq + 2);

                it = it2;
            }
            if(inffs.size()) {
                int a = *min_element(inffs.begin(), inffs.end());
                ans += now.size() - a;
            }
            else ans += cur_ans;

        }
        cout << ans + dup << endl;

    }


    return 0;
}
