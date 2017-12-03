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
    for (int i = 0; i < N; ++i) {
        bool is_empty = true;
        for (int j = 0; j < N; ++j)
            if (i != j && v[i].first < v[j].first && v[j].second < v[i].second) {
                is_empty = false;
                break;
            }
        
        if (is_empty)
            rest.push_back (v[i]);
        else
            lens.push_back (v[i].second - v[i].first);
    }

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
                                   rest[k].second - rest[i].first);
            }

    sort (lens.begin(), lens.end(), greater<int>());
    for (int j = 1; j < lens.size(); ++j) lens[j] += lens[j - 1];
    
    int best = max (dp[Z - 1][P], 0);
    
    if (!lens.empty())
        for (int j = 1; j < min(P,(int)lens.size()+1); ++j)
            if (dp[Z - 1][P - j] != -1)
                best = max (best, dp[Z - 1][P - j] + lens[j - 1]);
    
    if (best < 0)
        cout << "impossible" << endl;
    else
        cout << best << endl;
    
    return 0;
}
