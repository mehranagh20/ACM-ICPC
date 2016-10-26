//in the name of god
#include <bits/stdc++.h>

using namespace std;

bool myFunc(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
    if(a.first.second < b.first.second && a.first.second < b.second.second || a.second.second < b.first.second && a.second.second < b.second.second)
        return true;
    return false;
}

int main() {
    int n, nMass, nCase = 1;
    while(scanf("%d%d", &n, &nMass) == 2) {
        printf("Set #%d\n", nCase++);
        vector<pair<int, int>> nums(nMass);
        vector<pair<pair<int, int>, pair<int, int>>> solution;
        double avg = 0, imb = 0;
        for(int i = 0; i < nMass; i++) {
            scanf("%d", &nums[i].first);
            nums[i].second = i;
            avg += nums[i].first;
        }
        avg /= n;
        while(nums.size() < n * 2)
            nums.push_back(make_pair(0, nums[nums.size() - 1].second + 1));
        sort(nums.begin(), nums.end());
        int i = n - 1, j = n;
        while(j < 2 * n) {
            imb += abs((double)(nums[i].first + nums[j].first) - avg);
            solution.push_back(make_pair(make_pair(nums[i].first, 10000), make_pair(nums[j].first, 10000)));
            if(nums[i].first)
                solution[solution.size() - 1].first.second = nums[i].second;
            if(nums[j].first)
                solution[solution.size() - 1].second.second = nums[j].second;
            i--; j++;
        }
        sort(solution.begin(), solution.end(), myFunc);
        for(int i = 0; i < n; i++) {
            if(solution[i].first.second > solution[i].second.second) swap(solution[i].first, solution[i].second);
            printf(" %d:", i);
            if(solution[i].first.first)
                printf(" %d", solution[i].first.first);
            if(solution[i].second.first)
                printf(" %d", solution[i].second.first);
            puts("");
        }
        printf("IMBALANCE = %.5f\n\n", imb);
    }

    return 0;
}