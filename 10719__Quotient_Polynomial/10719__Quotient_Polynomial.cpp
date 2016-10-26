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

    int k;
    while (cin >> k) {
        cin.get();
        string tmp;
        getline(cin, tmp);
        stringstream ss;
        ss << tmp;
        vi coefs;
        int c;
        while (ss >> c)
            coefs.push_back(c);

        // synthetic division
        for (int i = 0; i < coefs.size() - 1; i++)
            coefs[i + 1] += coefs[i] * k;

        cout << "q(x):";
        for (int i = 0; i < coefs.size() - 1; i++)
            cout << ' ' << coefs[i];
        cout << endl;
        cout << "r = " << coefs.back() << endl;
        cout << endl;
    }


    return 0;
}