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

#define inf 1000000000
#define eps 1e-9

set<string> dic;

bool missing(string a, string b) {
    if(a.size() < b.size()) swap(a, b);
    if(a.size() - b.size() != 1) return false;
    int n = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i] != b[i - n]) n++;
    return n == 1;
}

bool adj(string a, string b) {
    if(a.size() != b.size()) return false;
    int n = 0;
    for(int i = 0; i < a.size(); i++) n += (a[i] != b[i]);
    return n == 1;
}

bool swa(string a, string b) {
    if(a.size() != b.size()) return false;
    int i = 0;
    for(; i < a.size(); i++) if(a[i] != b[i]) break;
    if(i == a.size() - 1) return false;
    if(a[i + 1] == b[i] && a[i] == b[i + 1]) {
        i += 2;
        for(; i < a.size(); i++) if(a[i] != b[i]) return false;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int n, q; cin >> n;
    string str;
    vs words;
    while(n--) {
        cin >> str; dic.insert(str), words.push_back(str);
    }
    cin >> q;
    while(q--) {
        cin >> str;
        if(dic.find(str) == dic.end()) {
            bool unknown = true;
            for(auto &e : words)
                if(missing(e, str) || adj(e, str) || swa(e, str)) {
                    cout << str << " is a misspelling of " << e << endl;
                    unknown = false;
                    break;

                }
            if(unknown) cout << str << " is unknown\n";
        }
        else cout << str << " is correct\n";

    }


    return 0;
}
