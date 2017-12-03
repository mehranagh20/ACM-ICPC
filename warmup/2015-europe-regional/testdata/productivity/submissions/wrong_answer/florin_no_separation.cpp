#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 205

typedef pair<int, int> pii;

int N, P;
vector<pii> v, rest;
vector<int> lens;

int dp[MAX_N][MAX_N]; // d[i][j] - i intervals into j groups; i >= j

int main () {
    cin >> N >> P;
    
    v.resize (N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;
    
    rest.resize (1);
    for (int i = 0; i < N; ++i)
        rest.push_back (v[i]);
    
    sort (rest.begin() + 1, rest.end());
    int Z = rest.size();
    
    memset (dp, 0x80, sizeof (dp));
    dp[0][0] = 0;
    
    for (int i = 1; i < Z; ++i)
        for (int j = 1; j <= P; ++j)
            for (int k = i; k >= 1; --k) {
                if (rest[k].second <= rest[i].first) break;
                
                if (dp[k - 1][j - 1] != -1)
                    dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] +
                                   rest[k].second - max(rest[i].first, rest[k].first));
                
            }
    
    int best = dp[Z - 1][P];
    
    if (best < 0)
        cout << 0 << endl;
    else
        cout << best << endl;
    
    return 0;
}
