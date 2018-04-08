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

int main() {
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vi scores(n);
    for(auto &e: scores) cin >> e;
    set<int> published, ans; // ans contains all the initial points that can be answer.
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        published.insert(tmp);
    }
    int lookup = *published.begin(); // just one of the published items
    for(int i = 1; i <= n; i++) { // assume that lookub is published after ith point
        set<int> already_published;
        already_published.insert(lookup);
        int tmp = lookup, num_of_found_published = 1;
        for(int j = i - 1; j > 0; j--) {
            tmp -= scores[j];
            if(published.find(tmp) != published.end() && already_published.find(tmp) == already_published.end())
                already_published.insert(tmp), num_of_found_published++;
        }
        int tmp2 = lookup;
        for(int j = i; j < n; j++) {
            tmp2 += scores[j];
            if(published.find(tmp2) != published.end() && already_published.find(tmp2) == already_published.end())
                already_published.insert(tmp2), num_of_found_published++;
        }
        if(num_of_found_published == m) ans.insert(tmp);
    }
    cout << ans.size() << endl;




    return 0;
}
