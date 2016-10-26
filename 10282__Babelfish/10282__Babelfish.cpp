//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2, s3;
    map<string, string> mp;
    while(true) {
        getline(cin, s1);
        if(s1.empty()) break;
        stringstream ss(s1); ss >> s2 >> s3;
        mp.insert(make_pair(s3, s2));
    }
    while(cin >> s1) {
        if(mp.find(s1) != mp.end())
            cout << mp[s1] << endl;
        else cout << "eh\n";
    }

    return 0;
}