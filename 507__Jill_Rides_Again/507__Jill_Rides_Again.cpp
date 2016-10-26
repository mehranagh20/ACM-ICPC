//In The Name Of God
#include <bits/stdc++.h>
using namespace std;

int arr[20100];

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++) cin >> arr[i];
        int f, s, tmpF, tmpS, mx = 0, sum = 0;
        int j;
        for(j = 0; j < n - 1 && arr[j] < 0; j++);
        f = j; s = j; tmpF = j; tmpS = j;
        for(j; j < n - 1; j++) {
            sum += arr[j];
            if(sum >= mx) {
                if((sum == mx && j - tmpF > s - f) || sum > mx) {
                        f = tmpF;
                        s = j;
                }
                mx = sum;
                tmpS = j;
            }
            if(sum < 0) {
                sum = 0;
                tmpF = j + 1;
            }
        }
        if(tmpS - tmpF > s - f) {f = tmpF; s = tmpS;}
        if(mx > 0) printf("The nicest part of route %d is between stops %d and %d\n", i, f + 1, s + 2);
        else printf("Route %d has no nice parts\n", i);
    }
    return 0;
}