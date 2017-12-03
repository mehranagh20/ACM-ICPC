#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;

pii intersect (pii a, pii b) {
    int lf = max (a.first, b.first);
    int rt = min (a.second, b.second);
    
    return make_pair(lf, rt);
}


int main () {
    int N, P;
    cin >> N >> P;
    
    vector<pair<int, pii> > v(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> v[i].second.first >> v[i].second.second;
        
        v[i].first = v[i].second.first - v[i].second.second;
    }
    
    sort (v.begin(), v.end());
    
    vector<vector<pii> > mp(P);
    
    for (int i = 0; i < P; ++i)
        mp[i].push_back (v[i].second);
    
    for (int i = P; i < N; ++i) {
        int maxlen = 0;
        int hit = -1;
        int bestHit = 2000000;
        for (int j = 0; j < P; ++j) {
            pii x = intersect (mp[j][0], v[i].second);
            
            // add where largest intersection, but if more possibilities take the smallest
            if (x.second - x.first == maxlen && mp[j][0].second - mp[j][0].first > bestHit) {
                hit = j;
                bestHit = mp[j][0].second - mp[j][0].first;
            }
            
            if (x.second - x.first > maxlen) {
                maxlen = x.second - x.first;
                hit = j;
                bestHit = mp[j][0].second - mp[j][0].first;
            }
        }
        
        if (hit == -1) break;
        
        mp[hit][0] = intersect (mp[hit][0], v[i].second);
    }
    
    int ans = 0;
    for (int i = 0; i < P; ++i)
        ans += mp[i][0].second - mp[i][0].first;
    
    printf ("%d\n", ans);
    
    return 0;
}