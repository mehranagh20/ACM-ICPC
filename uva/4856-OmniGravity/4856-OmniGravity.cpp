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

bool cmp(ii a, ii b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        vs grid(8);
        for(auto &e: grid) cin >> e;
        string vars = "ABCD";
        queue<vii> q;
        vii tmp;
        for(auto &c: vars) {
            for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) {
                if(grid[i][j] == c) {
                    tmp.push_back(ii(i, j));
                    break;
                }
            }
        }
        q.push(tmp);
        vs nngrid = grid;
        for(auto &e: nngrid) for(auto &ee: e) if(isalpha(ee)) ee = '.';

        set<vii> st;

        while(q.size()) {
            vii now = q.front(); q.pop();
            map<ii, int> mp;
            for(int i = 0; i < 4; i++) mp[now[i]] = i;

            vs ngrid = nngrid;
            sort(now.begin(), now.end());
            vii newupstate(4);
            for(auto &e: now) {
                int ind = mp[e];
                ii p1 = e, p2 = ii(e.first, e.second + 1);
                while(ngrid[p1.first][p1.second] != '#' && ngrid[p2.first][p2.second] != '#') {
                    p1.first--, p2.first--;
                    if(p1.first < 0) break;
                }
                p1.first++, p2.first++;
                newupstate[ind] = p1;
                for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) ngrid[p1.first + i][p1.second + j] = '#';
            }
            if(st.find(newupstate) != st.end()) st.insert(newupstate), q.push(newupstate);


            ngrid = nngrid;
            sort(now.begin(), now.end());
            for(int i = 3; i >= 0; i++) {
                ii e = now[i];
                int ind = mp[e];
                ii p1 = ii(e.first + 1, e.second), p2 = ii(e.first + 1, e.second + 1);
                while(ngrid[p1.first][p1.second] != '#' && ngrid[p2.first][p2.second] != '#') {
                    p1.first++, p2.first++;
                    if(p1.first > 7) break;
                }
                p1.first--, p2.first--;
                newupstate[ind] = p1;
                for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) ngrid[p1.first - i][p1.second + j] = '#';
            }
            if(st.find(newupstate) != st.end()) st.insert(newupstate), q.push(newupstate);


            ngrid = nngrid;
            sort(now.begin(), now.end(), cmp);
            for(auto &e: now) {
                int ind = mp[e];
                ii p1 = e, p2 = ii(e.first + 1, e.second);
                while(ngrid[p1.first][p1.second] != '#' && ngrid[p2.first][p2.second] != '#') {
                    p1.second--, p2.second--;
                    if(p1.second < 0) break;
                }
                p1.second++, p2.second++;
                newupstate[ind] = p1;
                for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) ngrid[p1.first + i][p1.second + j] = '#';
            }
            if(st.find(newupstate) != st.end()) st.insert(newupstate), q.push(newupstate);


            ngrid = nngrid;
            sort(now.begin(), now.end(), cmp);
            for(int i = 3; i >= 0; i--) {
                ii e = now[i];
                int ind = mp[e];
                ii p1 = ii(e.first, e.second + 1), p2 = ii(e.first + 1, e.second + 1);
                while(ngrid[p1.first][p1.second] != '#' && ngrid[p2.first][p2.second] != '#') {
                    p1.second++, p2.second++;
                    if(p1.second > 7) break;
                }
                p1.second--, p2.second--;
                newupstate[ind] = p1;
                for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) ngrid[p1.first + i][p1.second - j] = '#';
            }
            if(st.find(newupstate) != st.end()) st.insert(newupstate), q.push(newupstate);
        }
        cout << st.size() << endl;

    }

    return 0;
}
