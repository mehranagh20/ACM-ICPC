//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2) {
    if(p1.first > p2.first) return true;
    if(p1.first == p2.first && p1.second < p2.second) return true;
    return false;
}

int main() {
    string s, s2;
    while(true) {
        getline(cin, s); if(s == "0") break;
        map<string, int> mp; vector<pair<int, string>> vec;
        map<string, vector<string>> check;
        mp.insert(make_pair(s, 0));
        while(true) {
            getline(cin, s2);
            if(islower(s2[0])) {
                if(check.find(s2) == check.end()) {
                    vector<string> tmpV = {s};
                    check[s2] = tmpV;
                    mp[s]++;
                }
                else {
                    if(check[s2][0] == s) continue;
                    else {
                        if(check[s2].size() == 1) {
                            mp[check[s2][0]]--; check[s2].push_back("WTF");
                        }

                        continue;
                    }
                }
            }
            else if(s2 == "1") break;
            else {
                s = s2;
                mp[s2] = 0;
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++) vec.push_back(make_pair(it->second, it->first));
        sort(vec.begin(), vec.end(), comp);
        for(int i = 0; i < vec.size(); i++) cout << vec[i].second << " " << vec[i].first << endl;
    }

    return 0;
}