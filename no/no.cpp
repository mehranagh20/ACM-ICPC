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
    double pay, tot;
    int nMonths, n;
    while(cin >> nMonths >> pay >> tot >> n && nMonths >= 0) {
        vd perc(nMonths, -1);
        for(int i = 0; i < n; i++) {
            double p; int m; cin >> m >> p;
            perc[m] = 1 - p;
        }
        int desM = 0;
        double currP = perc[0];
        double carVal = (tot + pay) * currP;
        pay = tot / nMonths;
        while(tot > carVal) {
            desM++;
            if(perc[desM] != -1) currP = perc[desM];
            tot -= pay; carVal *= currP;
        }
        cout << desM << " ";
        if(desM > 1 || desM == 0) cout << "months" << endl;
        else cout << "month" << endl;
    }

    return 0;
}
