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
    string &TT = T;
    ios::sync_with_stdio(0);
    int tc = 0, nn;
    string a;
    vi indexOfChars(100000 + 10, 0);
    while(cin >> nn && nn) {
        if(tc++) cout << endl;
        T.clear();
        vi sizes = {0};
        int all = 0;
        for(int i = 0; i < nn; i++) {
            cin >> a;
            a += (char)i; // terminating char.
            for(int j = T.size(); j < a.size() + T.size(); j++) indexOfChars[j] = i;
            T += a;
            all += a.size(), sizes.push_back(all);
        }
        n = T.size();
        RA.assign(n, 0), SA.assign(n, 0), tempRA.assign(n, 0), tempSA.assign(n, 0), c.assign(n + 300, 0);
        constructSA();
        Phi.assign(n, 0); PLCP.assign(n, 0); LCP.assign(n, 0);
        computeLCP();

        // for(int i = 0; i < n; i++) {
        //     cout << LCP[i] << " ";
        //     for(int j = SA[i]; j < T.size(); j++) cout << T[j];
        //     cout << endl;
        // }

        int ansLen = 0, need = nn / 2 + 1, numDiff = 0, mn = inf, start = n - 1;
        vi ansInd, checkOwner(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) { // == 0 ?
            int ind = indexOfChars[SA[i]];
            if(checkOwner[ind] == 0) numDiff++;
            checkOwner[ind]++;
            while(numDiff == need) {
                if(mn >= ansLen && mn) {
                    if(mn == ansLen) ansInd.push_back(SA[i]);
                    else ansInd.clear(), ansInd.push_back(SA[i]), ansLen = mn;
                }
                ind = indexOfChars[SA[start]];
                checkOwner[ind]--;
                if(checkOwner[ind] == 0) numDiff--;
                start--;
                if(mn == LCP[start + 1]) {
                    mn = inf;
                    for(int j = start; j > i; j--) mn = min(mn, LCP[j]);
                }
            }
            mn = min(mn, LCP[i]);
        }
        // for(int i = need - 1; i < n; i++) {
        //     int numOwn = 0, len;
        //     len = LCP[i];
        //     // fill(checkOwner.begin(), checkOwner.end(), 0);
        //     for(int j = i; j >= 0; j--) {
        //         // int ind = lower_bound(sizes.begin(), sizes.end(), SA[j]) - sizes.begin();
        //         // if(sizes[ind] != SA[j]) ind--;
        //         int ind = indexOfChars[SA[j]];
        //         // if(checkOwner[ind]) break;
        //         if(!checkOwner[ind])
        //             checkOwner[ind] = 1, numOwn++;
        //         // if(numOwn == need || len < ansLen || len == 0) break;
        //         len = min(len, LCP[j]);
        //     }
        //     if(numOwn == need && len >= ansLen) {
        //         if(len == ansLen) ansInd.push_back(SA[i]);
        //         else ansInd.clear(), ansInd.push_back(SA[i]), ansLen = len;
        //     }
        // }
        if(need == 1) {
            for(int i = 0; i <= T.size() - 2; i++) cout << T[i];
            cout << endl;
        }
        else {
            if(!ansLen) cout << "?" << endl;
            else {
                string bef;
                for(int i = ansInd.size() - 1; i >= 0; i--) {
                    int e = ansInd[i];
                    string now;
                    for(int i = e; i < e + ansLen; i++) now += T[i];
                    if(bef != now) cout << now << endl;
                    bef = now;
                }
            }
        }

    }



    return 0;
}
