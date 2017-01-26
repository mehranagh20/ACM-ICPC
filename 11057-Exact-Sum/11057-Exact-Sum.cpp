#include<bits/stdc++.h>

using namespace std;

int nums[11000], n, m;

bool binSearch(int a, int l) {
    int low = l, high = n, mid, *tmp = nums;
    while(abs(high - low) >= 1) {
        mid = (low + high) / 2;
        if(nums[mid] + a == m)
            return true;
        else if(nums[mid] + a < m)
            low = mid + 1;
        else
            high = mid;
    }
    return false;
}

int main() {
    int i = 0;
    while(scanf("%d", &n) != EOF) {
        int fBook = -1, sBook = 1e9;
        for(int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        sort(nums, nums + n);
        scanf("%d", &m);
        for(int i = 0; i < n && nums[i] <= m; i++)
            if(binSearch(nums[i], i + 1) && abs(m - 2 * nums[i]) < abs(fBook - sBook)) {
                fBook = nums[i]; sBook = m - nums[i];
            }
        printf("Peter should buy books whose prices are %d and %d.\n\n", fBook, sBook);
    }

    return 0;
}