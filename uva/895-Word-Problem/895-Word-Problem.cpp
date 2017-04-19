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


int main() {
    //ios::sync_with_stdio(0);
    vector<string> words;
    string str;
    while(cin >> str && str != "#") words.push_back(str);
    getline(cin, str);
    while(getline(cin, str) && str != "#") {
        vector<char> chs; stringstream ss(str);
        while(ss >> str) chs.push_back(str[0]);
        int ans = 0;
        for(auto &word : words) {
            bool isOk = true;
            vector<bool> usedB(chs.size(), false);
            for(auto &c : word) {
                isOk = false;
                for (int i = 0; i < chs.size(); i++) {
                    if (chs[i] == c && !usedB[i]) {
                        usedB[i] = true;
                        isOk = true;
                        break;
                    }
                }
                if(!isOk) break;
            }
            if(isOk) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}