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
/*
1. qaz
2. wsx
3. edc
4. rfvtgb
5. space
6. space
7. yhnujm
8. ik,
9. ol.
10. p;/
*/

#define inf 1000000000
#define eps 1e-9

bool comp(string a, string b) {
    return a.size() < b.size();
}

int main() {
    ios::sync_with_stdio(0);
    vs fing = {"qaz", "wsx", "edc", "rfvtgb", " ", " ", "yhnujm", "ik,", "ol.",  "p;/"};
    vector<set<char>> ifbroken(10);
    set<char> all;
    for(int i = 0; i < 10; i++) for(auto &c : fing[i])
        ifbroken[i].insert(c), all.insert(c);
    int f, n;
    while(cin >> f >> n) {
        vi broken(10, 0);
        for(int i = 0; i < f; i++) {
            int tmp; cin >> tmp;
            broken[tmp - 1] = 1;
        }
        vs ans;
        while(n--) {
            string word; cin >> word;
            bool found = true;
            for(auto &c : word) {
                if(all.find(c) == all.end()) {
                    found = false;
                    break;
                }
                if(c == ' ' && broken[4] && broken[5]) {
                    found = false;
                    break;
                }
                else if(c != ' ') {
                    for(int i = 0; i < 10; i++) if(broken[i]) {
                        if(ifbroken[i].find(c) != ifbroken[i].end()) {
                            found = false;
                            break;
                        }

                    }
                }
            }
            if(found) ans.push_back(word);
        }
        sort(ans.begin(), ans.end(), comp);
        set<string> fin;
        if(ans.size())
            fin.insert(ans.back());
        for(int i = ans.size() - 2; i >= 0 && ans[i].size() == ans.back().size(); i--) fin.insert(ans[i]);
        cout << fin.size() << endl;
        for(auto e : fin) cout << e << endl;
    }


    return 0;
}
