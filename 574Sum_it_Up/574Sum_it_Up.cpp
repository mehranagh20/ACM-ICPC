#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> nums, tillNow;

void solution(int i, int j, map<vector<int>, int> &mp, int curr) {
    if (curr == t) {
        vector<int> tmp;
        for (int j = 0; j < i; j++)
            tmp.push_back(tillNow[j]);
        mp.insert(make_pair(tmp, i));
        return;
    }
    for (int k = j + 1; k < n; k++) {
        if (curr + nums[k] > t)
            continue;
        tillNow[i] = nums[k];
        solution(i + 1, k, mp, curr + nums[k]);
    }
}

int main() {
    while (scanf("%d%d", &t, &n) && n) {
        map<vector<int>, int> mp;
        nums.resize(n);
        tillNow.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        for (int i = 0; i < n; i++) {
            tillNow[0] = nums[i];
            solution(1, i, mp, nums[i]);
        }
        printf("Sums of %d:\n", t);
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            printf("%d", it->first[0]);
            for (int i = 1; i < it->second; i++)
                printf("+%d", it->first[i]);
            puts("");
        }
        if (!mp.size())
            printf("NONE\n");
    }

    return 0;
}