//In The Name Of God
#include <bits/stdc++.h>
using namespace std;

int arr[110][110];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(i) arr[i][j] += arr[i - 1][j];
            if(j) arr[i][j] += arr[i][j - 1];
            if(i && j) arr[i][j] -= arr[i - 1][j - 1];
        }
    int mx = 100000 * -127;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            for(int k = i; k < n; k++) for(int d = j; d < n; d++) {
                    int s = arr[k][d];
                    if(i) s -= arr[i - 1][d];
                    if(j) s-= arr[k][j - 1];
                    if(i && j) s += arr[i - 1][j - 1];
                    mx = max(mx, s);
                }
    cout << mx << endl;

    return 0;
}