#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums, nums2;
vector<pair<int, int>> leds;

bool solution(int val, int i, int burned) {
    vector<int> &tmpnums = nums, &tmpnums2 = nums2;
    vector<pair<int, int>> &tmpleds = leds;
    if (i == n)
        return true;
    if(val == 0)
        return false;
    if (leds[i].first & burned)
        return false;
    if (!(nums[val - 1] & leds[i].first)) {
        if (solution(val - 1, i + 1, burned | (nums[val - 1] ^ leds[i].second)))
            return true;
    }
    return false;
}

int main() {
    vector<int> &tmpnums = nums, &tmpnums2 = nums2;
    vector<pair<int, int>> &tmpleds = leds;
    nums = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4};
    for (auto &e : nums)
        nums2.push_back((1 << 7) - 1 - e);
    vector<int> &tmp = nums2;
    while (scanf("%d", &n) && n) {
        int burned = 0;
        while (getchar() != '\n');
        for (int j = 0; j < n; j++) {
            int tmp1 = 0, tmp2 = 0, fl = 1 << 6;
            for (int i = 0; i < 7; i++) {
                if (getchar() == 'Y')
                    tmp1 |= (fl >> i);
                else
                    tmp2 |= (fl >> i);
            }
            leds.push_back(make_pair(tmp1, tmp2)); //tmp2 is reverse N = 1;
            while (getchar() != '\n');
        }
        bool match = false;
        for (int i = 0; i < nums.size(); i++) {
            if (!(nums[i] & leds[0].first)) {//possible solution
                burned = nums[i] ^ leds[0].second;
                if (solution(i, 1, burned)) {
                    match = true;
                    break;
                }

            }
        }
        leds.clear();
        if(match)
            printf("MATCH\n");
        else printf("MISMATCH\n");

    }
    return 0;
}