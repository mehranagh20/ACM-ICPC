//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8
int m, n;

int way(int a) {
    if (a < 0) return m - 1;
    if (a >= m) return 0;
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    while (cin >> m >> n) {
        vvi nums(m, vi(n));
        vvi ansV(m, vi(n, inf));
        vector<vvi> tmpAns(m, vvi(n, vi(0)));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> nums[i][j];
        for (int i = 0; i < m; i++) {
            ansV[i][0] = nums[i][0];
            tmpAns[i][0].push_back(i);
        }
        for (int j = 1; j < n; j++)
            for (int i = 0; i < m; i++) {
                int ind = way(i - 1);
                if((ansV[i][j - 1] < ansV[way(i - 1)][j - 1] || (ansV[i][j - 1] == ansV[way(i - 1)][j - 1] && tmpAns[i][j - 1] < tmpAns[way(i - 1)][j - 1])))
                    ind = i;
                if(!(ansV[ind][j - 1] < ansV[way(i + 1)][j - 1] || (ansV[ind][j - 1] == ansV[way(i + 1)][j - 1] && tmpAns[ind][j - 1] < tmpAns[way(i + 1)][j - 1])))
                    ind = way(i + 1);
                tmpAns[i][j] = tmpAns[ind][j - 1]; tmpAns[i][j].push_back(i);
                ansV[i][j] = ansV[ind][j - 1] + nums[i][j];
            }
        int ind = 0;
        for(int i = 0; i < m; i++) if(ansV[i][n - 1] < ansV[ind][n - 1] || (ansV[ind][n - 1] == ansV[i][n - 1] && tmpAns[i][n - 1] < tmpAns[ind][n - 1]))
                ind = i;
        auto rAns = tmpAns[ind][n - 1];
        cout << rAns[0] + 1;
        for(int i = 1; i < rAns.size(); i++) cout << " " << rAns[i] + 1;
        cout << endl;
        cout << ansV[ind][n - 1] << endl;
    }
    return 0;
}