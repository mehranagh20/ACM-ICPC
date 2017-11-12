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

ll sieve_size;
bitset<1000> bs;

void sieve(ll upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
        for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
    }
}

int bfs(vi init) {
    map<vi, int> dis;
    queue<vi> q;
    q.push(init), dis[init] = 0;
    while(!q.empty()) {
        vi cur = q.front(); q.pop();
        bool found = true;
        for(int i = 1; i <= 8; i++) if(abs(cur[i - 1]) != i)
            found = false;
        if(found) return dis[cur];
        for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++)
            if(cur[i] * cur[j] < 0 && bs[abs(cur[i]) + abs(cur[j])]) {
                vi tmp, tmp2;
                for(int k = 0; k < j; k++)
                    if(k != i) tmp.push_back(cur[k]);
                tmp.push_back(cur[i]);
                for(int k = j; k < 8; k++)
                    if(k != i) tmp.push_back(cur[k]);
                if(dis.find(tmp) == dis.end()) {
                    dis[tmp] = dis[cur] + 1;
                    q.push(tmp);
                }

                for(int k = 0; k <= j; k++)
                    if(k != i) tmp2.push_back(cur[k]);
                tmp2.push_back(cur[i]);
                for(int k = j + 1; k < 8; k++)
                    if(k != i) tmp2.push_back(cur[k]);
                if(dis.find(tmp2) == dis.end()) {
                    dis[tmp2] = dis[cur] + 1;
                    q.push(tmp2);
                }
            }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    sieve(100);
    int n, tc = 0;
    while(cin >> n && n) {
        vi init = {n};
        for(int i = 0; i < 7; i++) {
            int tmp; cin >> tmp;
            init.push_back(tmp);
        }
        cout << "Case " << ++tc << ": ";
        cout << bfs(init) << endl;
    }

    return 0;
}
