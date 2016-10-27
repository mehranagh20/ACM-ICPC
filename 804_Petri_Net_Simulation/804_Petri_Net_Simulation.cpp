// In The Name Of God
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

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 0;
    while (cin >> n && n) {
        vi places(n, 0);
        for (int i = 0; i < n; i++)
            cin >> places[i];
        int t;
        cin >> t;
        vector<pair<map<int, int>, vi>> trans(t);
        for (int i = 0; i < t; i++) {
            int tmp;
            while (cin >> tmp && tmp) {
                if (tmp < 0) {
                    tmp = -tmp - 1;
                    if (trans[i].first.find(tmp) == trans[i].first.end())
                        trans[i].first[tmp] = 1;
                    else trans[i].first[tmp]++;
                }
                else {
                    trans[i].second.push_back(tmp - 1);
                }
            }
        }
        int tr = 0, nf; cin >> nf;
        while(tr < nf) {
            bool found = false;
            for(auto &e : trans) {
                bool f = true;
                for(auto it = e.first.begin(); it != e.first.end(); it++) {
                    if(places[it->first] < it->second) {
                        f = false;
                        break;
                    }
                }
                if(f) {
                    for(auto ee : e.second) places[ee]++;
                    for(auto it = e.first.begin(); it != e.first.end(); it++) places[it->first] -= it->second;
                    tr++;
                    if(tr >= nf) break;
                    found = true;
                }
            }
            if(!found) break;
        }
        cout << "Case " << ++tc << ": ";
        if(tr < nf) {
            cout << "dead after " << tr << " transitions" << endl << "Places with tokens:";
            for(int i = 0; i < places.size(); i++) if(places[i]) cout << " " << i + 1 << " (" << places[i] << ")";
            cout << endl << endl;
        }
        else {
            cout << "still live after " << nf << " transitions\n" << "Places with tokens:";
            for(int i = 0; i < places.size(); i++) if(places[i]) cout << " " << i + 1 << " (" << places[i] << ")";
            cout << endl << endl;

        }


    }

    return 0;
}
