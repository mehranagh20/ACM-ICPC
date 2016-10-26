//In The Name Of God
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define inf 1000000000

//could use TSP but it was overKill :| used brute force in 5min :))

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 0;
    while(cin >> n && n) {
        printf("**********************************************************\nNetwork #%d\n", ++tc);
        vector<pair<int, int>> coor(n);
        vector<vector<double>> dis(n, vector<double>(n, 0.0));
        for(int i = 0; i < n; i++) cin >> coor[i].first >> coor[i].second;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
                dis[i][j] = sqrt(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2)) + 16;
                dis[j][i] = dis[i][j];
            }
        vi nums(n), ansV;
        double total = inf;
        for(int i = n - 1; i >= 0; i--) nums[i] = i;
        do {
            double tmp = 0;
            for(int i = 0; i < n - 1; i++) tmp += dis[nums[i]][nums[i + 1]];
            if (tmp < total) {
                total = tmp;
                ansV = nums;
            }
        } while(next_permutation(nums.begin(), nums.end()));
        for(int i = 0; i < n - 1; i++) printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", coor[ansV[i]].first, coor[ansV[i]].second, coor[ansV[i + 1]].first, coor[ansV[i + 1]].second, dis[ansV[i]][ansV[i + 1]]);
        printf("Number of feet of cable required is %.2lf.\n", total);
    }
    return 0;
}