//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vi order(200);

bool func(string a, string b) {
    for(int i = 0; i < a.size(); i++) {
        if(order[a[i]] < order[b[i]]) return true;
        else if(order[b[i]] < order[a[i]]) return false;
    }
    return false;
}

int main() {
    int ind = 0;
    for(int i = 0; i < 26; i++) {
        order[i + 65] = ind++;
        order[i + 97] = ind++;
    }
    int n; cin >> n;
    while(n--) {
        vs ans;
        string str; cin >> str;
        sort(str.begin(), str.end());
        do {
            ans.push_back(str);
        } while(next_permutation(str.begin(), str.end()));
        sort(ans.begin(), ans.end(), func);
        for(auto &e : ans) cout << e << endl;
    }

    return 0;
}