//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
map<string, vector<pair<pair<int, int>, string>>> mp;


bool sol(string  &a, string &b, set<string> &st, pair<int, int> &ans) {
    map<string, vector<pair<pair<int, int>, string>>> &mmp = mp;
    auto it = mp.find(b);
    for(auto &e : it->second) {
        if(e.second == a) {
            ans = e.first; swap(ans.first, ans.second);
            return true;
        }
        else if(st.find(e.second) == st.end()) {
            st.insert(e.second);
            if(sol(a, e.second, st, ans)) {
                ans.first *= e.first.second;
                ans.second *= e.first.first;
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    char c;
    string string1, string2;
    int a, b;
    while(cin >> c && c != '.') {
        if(c == '!') {
            cin >> a >> string1 >> c >> b >> string2;
            if (mp.find(string1) == mp.end()) mp.insert(make_pair(string1, vector<pair<pair<int, int>, string>>()));
            if (mp.find(string2) == mp.end()) mp.insert(make_pair(string2, vector<pair<pair<int, int>, string>>()));
            int g = gcd(a, b);
            mp[string2].push_back(make_pair(make_pair(b / g, a / g), string1));
            mp[string1].push_back(make_pair(make_pair(a / g, b / g), string2));
        }
        else {rejl
            cin >> string1 >> c >> string2;
            pair<int, int> ans;
            set<string> st;
            if(sol(string1, string2, st, ans)) {
                int g = gcd(ans.first, ans.second);
                cout << ans.first / g << " " << string1 << " = " << ans.second / g << " " << string2 << endl;
            }
            else cout << "? " << string1 << " = " << "? " << string2 << endl;
        }
    }

    return 0;
}