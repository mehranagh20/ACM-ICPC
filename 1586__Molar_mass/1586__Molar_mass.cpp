#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);

    map<char, double> mol;
    mol['C'] = 12.01; mol['H'] = 1.008; mol['O'] = 16; mol['N'] = 14.01;

    int t; cin >> t;
    while (t--) {
        string formula; cin >> formula;
        char cur = 0;
        map<char, int> atoms;
        int count = 0;
        for (int i = 0; i < formula.size(); i++) {
            if (formula[i] >= 'C') {
                if (cur > 0)
                    atoms[cur] += count;
                if (count == 0) {
                    atoms[cur] += 1;
                }
                cur = formula[i];
                count = 0;
            }
            else
                count = count * 10 + (formula[i] - '0');
        }
        atoms[cur] += count == 0 ? 1 : count;
        double ans = 0;
        for (map<char, int>::iterator i = atoms.begin(); i != atoms.end(); i++)
            ans += i->second * mol[i->first];
        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}