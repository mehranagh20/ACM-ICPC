#include <bits/stdc++.h>

 using namespace std;
 
 int main() {
     int t;
     scanf("%d", &t);
     while (t--) {
         int n, ans = 100000;
         scanf("%d", &n);
         vector<vector<int>> nums(n);
         for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++) {
                 int tmp;
                 scanf("%d", &tmp);
                 nums[i].push_back(tmp);
             }
         sort(nums.begin(), nums.end());
         do {
             int currAns = 0;
             vector<bool> colSel(n, false);
             for(auto &e : nums) {
                 int tmp = 1000000, sJ;
                 for(int i = 0; i < n; i++) {
                     if(!colSel[i] && e[i] < tmp) {
                         tmp = e[i];
                         sJ = i;
                     }
                 }
                 colSel[sJ] = true;
                 currAns += tmp;
             }
             if(currAns < ans)
                 ans = currAns;
         } while(next_permutation(nums.begin(), nums.end()));
         printf("%d\n", ans);
     }
     return 0;
 }

