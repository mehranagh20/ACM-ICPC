//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

int main() {
    int tc; cin >> tc;
    while(tc--) {
        string str; cin >> str;
        llu tot = 0;
        int p = str.size();
        for(int i = 0; i < str.size(); i++){
            tot += pow(str[i] - '0', p);
        }
        if(tot == stoull(str)) cout << "Armstrong\n";
        else cout << "Not Armstrong\n";
    }

    return 0;
}
