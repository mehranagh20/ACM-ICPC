#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

int main() {
    ios::sync_with_stdio(0);
    int tC, nl = 0; cin >> tC;
    while(tC--) {
        if(nl++) cout << endl;
        viii he;
        int a, b, c;
        cin >> a >> b >> c;
        long long ans = -200000000000000000;
        he.resize(a, vii(b, vi(c)));
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int k = 0; k < c; k++) {
                    cin >> he[i][j][k];
                    if (k) he[i][j][k] += he[i][j][k - 1];
                    if (j) he[i][j][k] += he[i][j - 1][k];
                    if (k && j) he[i][j][k] -= he[i][j - 1][k - 1];
                }
        for (int i = 0; i < b; i++)
            for (int j = 0; j < c; j++)
                for (int ii = i; ii < b; ii++)
                    for (int jj = j; jj < c; jj++) {
                        vector<long long> thState;
                        for (int r = 0; r < a; r++) {
                            long long tmp = he[r][ii][jj];
                            if (i) tmp -= he[r][i - 1][jj];
                            if (j) tmp -= he[r][ii][j - 1];
                            if (i && j) tmp += he[r][i - 1][j - 1];
                            thState.push_back(tmp);
                        }
                        long long sum = 0, tAns = -200000000000000000;
                        for (int i = 0; i < thState.size(); i++) {
                            sum += thState[i];
                            tAns = max(tAns, sum);
                            if (sum < 0) sum = 0;
                        }
                        ans = max(ans, tAns);
                    }
        cout << ans << endl;
    }

    return 0;
}