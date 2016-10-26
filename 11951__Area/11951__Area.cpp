//In The Name Of God
#include <bits/stdc++.h>

using namespace std;
int arr[110][110];

int main() {
    ios::sync_with_stdio(0);
    int tc, n, m, mon; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        int ansSize = 0, ansMon = 0;
        cin >> n >> m >> mon;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
                if(i) arr[i][j] += arr[i - 1][j];
                if(j) arr[i][j] += arr[i][j - 1];
                if(i && j) arr[i][j] -= arr[i - 1][j - 1];
            }
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
                for(int ii = i; ii < n; ii++) for(int jj = j; jj < m; jj++) {
                        int tmp = arr[ii][jj];
                        if(i) tmp -= arr[i - 1][jj];
                        if(j) tmp -= arr[ii][j - 1];
                        if(i && j) tmp += arr[i - 1][j - 1];
                        if(((jj - j + 1) * (ii - i + 1) > ansSize && tmp <= mon) || ((jj - j + 1) * (ii - i + 1)) == ansSize && tmp < ansMon) {
                            ansMon = tmp;
                            ansSize = (jj - j + 1) * (ii - i + 1);
                        }
                    }
        cout << ansSize << " " << ansMon << endl;
    }

    return 0;
}