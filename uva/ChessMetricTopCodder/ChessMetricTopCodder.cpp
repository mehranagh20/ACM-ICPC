#include <bits/stdc++.h>

using namespace std;
unsigned long long int arr[110][110][51];


int main() {
    ios::sync_with_stdio(0);
    pair<int, int> st = {0, 0}, fi = {0 , 99};
    int way = 50, size = 100; arr[st.first + 2][st.second + 2][0] = 1;
    for(int m = 1; m < way; m++) for(int i = 2; i < size + 2; i++)
            for(int j = 2; j < size + 2; j++) {
                arr[i][j][m] = arr[i - 1][j][m - 1] + arr[i][j - 1][m - 1] + arr[i + 1][j][m - 1] + arr[i][j + 1][m - 1] + arr[i - 1][j - 1][m - 1] + arr[i - 1][j + 1][m - 1] +
                        arr[i + 1][j - 1][m - 1] + arr[i + 1][j + 1][m - 1] + arr[i - 1][j - 2][m - 1] + arr[i - 1][j + 2][m - 1] + arr[i + 1][j + 2][m - 1] +
                        arr[i + 1][j - 2][m - 1] + arr[i - 2][j  - 1][m - 1] + arr[i - 2][j + 1][m - 1] + arr[i + 2][j + 1][m - 1] + arr[i + 2][j - 1][m - 1];
            }
    int i = fi.first + 2, j = fi.second + 2, m = way;
    unsigned long long ans = arr[i - 1][j][m - 1] + arr[i][j - 1][m - 1] + arr[i + 1][j][m - 1] + arr[i][j + 1][m - 1] + arr[i - 1][j - 1][m - 1] + arr[i - 1][j + 1][m - 1] +
                                            arr[i + 1][j - 1][m - 1] + arr[i + 1][j + 1][m - 1] + arr[i - 1][j - 2][m - 1] + arr[i - 1][j + 2][m - 1] + arr[i + 1][j + 2][m - 1] +
                                            arr[i + 1][j - 2][m - 1] + arr[i - 2][j  - 1][m - 1] + arr[i - 2][j + 1][m - 1] + arr[i + 2][j + 1][m - 1] + arr[i + 2][j - 1][m - 1];
    printf("%llu\n", ans);

    return 0;
}