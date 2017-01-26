//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
#define inf 1000000000

//question description sucks :| you can get acc with either just going up and left and then land to destination or by comming down any time you want :|

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n; n /= 100;
        vector<vector<int>> wind(10, vector<int>(n)), ans(10, vector<int>(n, inf));
        for(int i = 0; i < 10; i++) for(int j = 0; j < n; j++) cin >> wind[i][j];
        ans[9][0] = 0;
        for(int i = 9; i > 0; i--) for (int j = 0; j < n - 1; j++) {
                ans[i][j + 1] = min(ans[i][j + 1], ans[i][j] + 30 - wind[i][j]);
                ans[i - 1][j + 1] = min(ans[i - 1][j + 1], ans[i][j] + 60 - wind[i][j]);
            }
        for(int i = 0; i < 8; i++) for(int j = 0; j < n - 1; j++) {
                if(ans[i][j] == inf) continue;
                ans[i][j + 1] = min(ans[i][j + 1], ans[i][j] + 30 - wind[i][j]);
                ans[i + 1][j + 1] = min(ans[i + 1][j + 1], ans[i][j] + 20 - wind[i][j]);
            }
        cout << min(ans[9][n - 1] + 30 - wind[9][n - 1], ans[8][n - 1] + 20 - wind[8][n - 1]) << endl << endl;

    }

    return 0;
}