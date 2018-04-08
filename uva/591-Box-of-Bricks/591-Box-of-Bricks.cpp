#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, TC = 1;
    while(cin >> n && n) {
        int s = 0, ans = 0;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i]; s += arr[i];
        }
        int avg = s / n;
        for(int i = 0; i < n; i++)
            if(arr[i] > avg)
                ans += arr[i] - avg;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", TC++, ans);
    }
    return 0;
}