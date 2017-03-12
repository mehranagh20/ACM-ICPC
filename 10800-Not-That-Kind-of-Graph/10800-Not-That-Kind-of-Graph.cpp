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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    map<char, char> mp = {{'F', '\\'}, {'R', '/'}, {'C', '_'}};
    for(int i = 0; i < tc; i++) {
        cout << "Case #" << i + 1 << ":" << endl;
        string str; cin >> str;
        vs graph(150);
        int mxi = 70, mni = 70, curi = 70, curj = 0;
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            int nowi = (c == 'F' ? curi - 1 : curi);
            if(i == 0) mxi = nowi, mni = nowi;
            while(graph[nowi].size() < curj + 1) graph[nowi] += ' ';
            graph[nowi][curj] = mp[c];
            mxi = max(mxi, nowi), mni = min(mni, nowi), curj++;
            if(c == 'F') curi--;
            if(c == 'R') curi++;

        }
        while(mni <= mxi) {
            cout << "| " << graph[mxi] << endl;
            mxi--;
        }
        cout << "+";
        for(int i = 0; i <= curj + 1; i++) cout << "-";
        cout << endl << endl;
    }


    return 0;
}
