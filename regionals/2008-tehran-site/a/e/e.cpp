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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

vs split(char d, int i, string s) {
    vs tmp;
    string t;
    while(i < s.size()) {
        if(s[i] == d) {
            if(t != "")
                tmp.push_back(t);
            t = "";
            i++;
            continue;
        }
        t += s[i];
        i++;
    }
    if(t != "")
        tmp.push_back(t);
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    vector<map<string, int>> lvl;
    vs dirs(1000);
    int cur_lvl = 0;
    bool read = true;
    string s;
    while(true) {
        if(read)
            getline(cin, s);
        read = true;
        vs all = split(' ', 1, s);
        if(!all.size()) {
            lvl.clear();
            dirs = vs(1000);
            cur_lvl = 0;
            continue;
        }
        if(all[0] == "exit") break;
        if(all[0] == "cd") {
            vs cur;
            if(all[1][0] == '\\') {
                cur = split('\\', 1, all[1]);
                cur_lvl = 0;
            }
            if(all[1][0] != '\\') cur = split('\\', 0, all[1]);
            for(auto &e: cur) {
                if(e == "..") cur_lvl--;
                else {
                    if(lvl.size() <= cur_lvl) lvl.push_back(map<string, int>());
                    if(lvl[cur_lvl].find(e) == lvl[cur_lvl].end()) lvl[cur_lvl][e] = 0;
                    cur_lvl++;
                    dirs[cur_lvl] = e;
                }
            }

        }
        else if(all[0] == "dir") {
            string t;
            int tot = 0;
            while(getline(cin, t) && t != "") {
                if(t[0] == '>') {
                    read = false;
                    s = t;
                    break;
                }
                vs cur = split(' ', 0, t);
                if(cur.size() == 1) {
                    if(lvl.size() <= cur_lvl) lvl.push_back(map<string, int>());
                    if(lvl[cur_lvl].find(cur[0]) == lvl[cur_lvl].end()) lvl[cur_lvl][cur[0]] = 0;
                }
                else
                    tot += stoi(cur[1]);
            }
            for(int i = 0; i < cur_lvl; i++) lvl[i][dirs[i + 1]] += tot;
        }

        else {
            vs cur;
            int l = cur_lvl;
            if(all[1][0] == '\\') {
                cur = split('\\', 1, all[1]);
                l = 0;
            }
            if(all[1][0] != '\\') cur = split('\\', 0, all[1]);
            for(auto &e: cur) {
                if(e == "..") l--;
                else {
                    if(lvl.size() <= l) lvl.push_back(map<string, int>());
                    if(lvl[l].find(e) == lvl[l].end()) lvl[l][e] = 0;
                    l++;
                    dirs[l] = e;
                }
            }
            cout << lvl[l - 1][dirs[l]] << endl;

        }

        if(all[0] == "exit") break;
    }


    return 0;
}
