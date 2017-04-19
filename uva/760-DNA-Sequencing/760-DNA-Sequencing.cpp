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

string T; // the input string
int n; // n is size of input string
vi RA, tempRA, SA, tempSA, c; // RA is rank array, SA is suffix array

void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    fill(c.begin(), c.end(), 0);
     for (i = 0; i < n; i++)
         c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for(int i = 0; i < tempSA.size(); i++) SA[i] = tempSA[i];
}

void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] =
                    (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        RA = tempRA;
        if (RA[SA[n - 1]] == n - 1) break;
    }
}

vi Phi, PLCP, LCP; // LCP is the longest common prefix

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}

// resize the arrays in main, set n
int main() {
    ios::sync_with_stdio(0);
    string a, b;
    int tc = 0;
    while(cin >> a >> b) {
        if(tc++) cout << endl;
        a += (char)0, b += (char)1;
        T = a + b;
        n = T.size();
        RA.assign(n, 0), SA.assign(n, 0), tempRA.assign(n, 0), tempSA.assign(n, 0), c.assign(n + 300, 0);
        constructSA();
        Phi.assign(n, 0); PLCP.assign(n, 0); LCP.assign(n, 0);
        computeLCP();
        int bef = SA[0] < a.size(), ans = 0;
        for(int i = 1; i < T.size(); i++) {
            int cur = SA[i] < a.size();
            ans = max(ans, cur == bef ? 0 : LCP[i]), bef = cur;
        }
        if(!ans) cout << "No common sequence.\n";
        else {
            bef = SA[0] < a.size();
            string last;
            for(int i = 1; i < T.size(); i++) {
                int cur = SA[i] < a.size();
                if(cur != bef && LCP[i] == ans) {
                    string now;
                    for(int j = SA[i]; j < SA[i] + ans; j++) now += T[j];
                    if(now != last) cout << now << endl;
                    last = now;
                }
                bef = cur;
            }
        }
    }



    return 0;
}
