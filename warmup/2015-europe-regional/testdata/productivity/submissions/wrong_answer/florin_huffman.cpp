#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define MAX_N 205

typedef pair<int, int> pii;

int N, P;
vector<pii> v, rest;
vector<int> lens;

pii intersect (pii a, pii b) {
    int lf = max (a.first, b.first);
    int rt = min (a.second, b.second);
    
    return make_pair(lf, rt);
}

int main () {
    cin >> N >> P;
    
    set<pii> x;
    
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        
        x.insert (make_pair(a,b));
    }
    
    while (x.size() > P) {
        int maxlen = 0;
        pii newint;
        pii rm, rm1;
        
        for (set<pii>::iterator it = x.begin(); it != x.end(); ++it) {
            set<pii>::iterator start = it;
            
            for (set<pii>::iterator it1 = ++start; it1 != x.end(); ++it1) {
                pii actint = intersect (*it, *it1);
                
                if (actint.second - actint.first > maxlen) {
                    maxlen = actint.second - actint.first;
                    newint = actint;
                    rm = *it;
                    rm1 = *it1;
                }
            }
        }
        
        if (maxlen > 0) {
            x.erase (x.find(rm));
            x.erase (x.find(rm1));
                
            x.insert (newint);
        } else break;
            
        if (x.size() <= P) break;
    }
    
    int ans = 0;
    for (set<pii>::iterator it = x.begin(); it != x.end(); ++it)
        ans += it->second - it->first;
    
    printf ("%d\n", ans);
    
    return 0;
}
