//in the name of god...
#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> nums;
int n, l, w;

int solution() {
    vector<pair<double, double>> &nu = nums;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
        nums[i].second *= -1;
    double range = 0.0;
    for(int i = 0; i < nums.size(); i++) {
        if(range>= l) return ans;
        if(nums[i].second<= range)
            continue;
        if(nums[i].first > range) return -1;
        int j = i, k = i;
        while(j < nums.size() && nums[j].first <= range) {
            if (nums[j].second > nums[k].second) k = j;
            j++;
        }
        range = nums[k].second;
        i = k;
        ans++;
    }
    return (range >= l ? ans : -1);
}

int main() {
    while(scanf("%d%d%d", &n, &l, &w) == 3) {
        nums.clear();
        for(int i = 0; i < n; i++) {
            int c, r;
            scanf("%d%d", &c, &r);
            if(2. * r <= w) continue;
            double x = sqrt((long long)r * (long long)r - ((long long)w / 2.) * ((long long)w / 2.));
            nums.push_back(make_pair(c - x, -c - x));
        }
        sort(nums.begin(), nums.end());
        printf("%d\n", solution());
    }

    return 0;
}