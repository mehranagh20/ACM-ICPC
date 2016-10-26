//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8
int n;
set<pair<char, char> > st;
vector<char> vc;
vector<string> ways;

void sol(string &s, int bitmask) {
    if(s.size() == n) {
        ways.push_back(s);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(bitmask & (1 << i)) continue;
        bool found = false;
        for(auto &c : s) {
            if (st.find(make_pair(vc[i], c)) != st.end()) {
                found = true;
                break;
            }
        }
        if(found) continue;
        string ss = s + vc[i];
        sol(ss, bitmask | (1 << i));
    }
}


int main() {
    //ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(getchar() != '\n');
    vector<char> &tC = vc;
    set<pair<char, char>> &stt = st;
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        ways.clear();
        while(getchar() != '\n');
        string tmp;
        getline(cin, tmp);
        vc.clear();
        stringstream ss(tmp);
        while(ss >> tmp) vc.push_back(tmp[0]);
        n = vc.size();
        getline(cin, tmp);
        stringstream sss(tmp);
        st.clear();
        while(sss >> tmp)
            st.insert(make_pair(tmp[0], tmp[2]));
        tmp.clear();
        sol(tmp, 0);
        if(!ways.size()) cout << "NO" << endl;
        else {
            sort(ways.begin(), ways.end());
            for(auto &str : ways) {
                cout << str[0];
                for (int i = 1; i < str.size(); i++) cout << " " << str[i];
                cout << endl;
            }
        }
    }

    return 0;
}