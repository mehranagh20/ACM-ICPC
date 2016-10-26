//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8
#define maxStr "999999999999999999999999999999999999999999999999999999999999999999999999999"

string str;
map<char, char>mp = {{'2', '5'}, {'6', '9'}, {'5', '2'}, {'9', '6'}};

string exch(int ind) {
    string ans = maxStr, tmp = str;
    for(int i = str.size() - 1; i >= ind; i--) {
        if(str[i] == '.') continue;
        tmp = str;
        if(str[i] > str[ind]) {
            swap(tmp[i], tmp[ind]);
            if(tmp > str && tmp < ans) ans = tmp;
        }

        if(mp.find(str[i]) != mp.end() && mp[str[i]] > str[ind]) {
            tmp = str; tmp[i] = mp[tmp[i]];
            swap(tmp[i], tmp[ind]);
            if(tmp > str && tmp < ans) ans = tmp;
        }
        if(mp.find(str[ind]) != mp.end() && mp[str[ind]] < str[i]) {
            tmp = str; tmp[ind] = mp[str[ind]];
            swap(tmp[ind], tmp[i]);
            if(tmp > str && tmp < ans)
                ans = tmp;
        }
        if(mp.find(str[ind]) != mp.end() && mp.find(str[i]) != mp.end() && mp[str[ind]] < mp[str[i]]) {
            tmp = str; tmp[ind] = mp[str[ind]]; tmp[i] = mp[str[i]];
            swap(tmp[i], tmp[ind]);
            if(tmp > str && tmp < ans) ans = tmp;
        }
    }
    return ans;
}

void makeItSmall(string &ans) {
    string tmp = ans;
    for(int i = ans.size() - 1; i >= 0; i--) {
        for(int j = ans.size() - 1; j > 0; j--) {
            if(ans[j] == '.') continue;
            int tmpj = j - 1;
            if(ans[j - 1] == '.') tmpj--;
            if(ans[j] < ans[tmpj]) {
                tmp = ans; swap(tmp[j], tmp[tmpj]);
                if(tmp > str && tmp < ans) ans = tmp;
            }
            if(mp.find(ans[j]) != mp.end() && mp[ans[j]] < ans[tmpj]) {
                tmp = ans; tmp[j] = mp[tmp[j]]; swap(tmp[j], tmp[tmpj]);
                if(tmp > str && tmp < ans) ans = tmp;
            }
            if(mp.find(ans[tmpj]) != mp.end() && ans[j] < mp[ans[tmpj]]) {
                tmp = ans; tmp[j - 1] = mp[tmp[j - 1]]; swap(tmp[j], tmp[j - 1]);
                if(tmp > str && tmp < ans) ans = tmp;
            }
            if(mp.find(ans[j]) != mp.end() && mp.find(ans[tmpj]) != mp.end() && mp[ans[j]] < mp[ans[tmpj]]) {
                tmp = ans; tmp[tmpj] = mp[tmp[tmpj]]; tmp[j] = mp[tmp[j]]; swap(tmp[j], tmp[tmpj]);
                if(tmp > str && tmp < ans) ans = tmp;
            }
            if(mp.find(ans[j]) != mp.end() && mp[ans[j]] < ans[j]) {
                tmp = ans; tmp[j] = mp[tmp[j]];
                if(tmp > str && tmp < ans) ans = tmp;
            }
        }
    }
}


int main() {
    //ios::sync_with_stdio(0);
    while(cin >> str && str != ".") {
        string ans; bool possible = false;
        for(int i = str.size() - 1; i >= 0; i--) {
            if(str[i] == '.') continue;
            string tmp = exch(i);
            if(tmp > str && tmp != maxStr) {
                possible = true;
                ans = tmp;
                break;
            }
        }
        if(possible) {
            makeItSmall(ans);
            cout << ans << endl;
        }
        else cout << "The price cannot be raised.\n";
    }

    return 0;
}