#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE

const int MOD = 50000017;
int size;
unsigned long long K[MOD];
int T[MOD];

unsigned long long myhash(int x, int y) {
    unsigned long long key = ((unsigned long long)x << 20) | y;
    key = (~key) + (key << 21);
    key = key ^ (key >> 24);
    key = (key + (key << 3)) + (key << 8);
    key = key ^ (key >> 14);
    key = (key + (key << 2)) + (key << 4);
    key = key ^ (key >> 28);
    key = key + (key << 31);
    return key;
}
void add(int x, int y) {
    while (x <= size) {
        int y1 = y;
        while (y1 <= size) { 
            unsigned long long key = myhash(x,y1);
            int kde = key % MOD;
            while (K[kde] && K[kde] != key) { ++kde; if (kde==MOD) kde=0; }
            K[kde] = key;
            ++T[kde];
            y1 += y1 & -y1; 
        }
        x += x & -x;
    }
}

int sum(int x, int y) {
    int res=0;
    while (x) { 
        int y2=y;
        while (y2) { 
            unsigned long long key = myhash(x,y2);
            int kde = key % MOD;
            while (K[kde] && K[kde] != key) { ++kde; if (kde==MOD) kde=0; }
            res += T[kde];
            y2 -= y2 & -y2; 
        }
        x -= x & -x;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    
    map<int,int> translate;
    for (int n=0; n<N; ++n) { int x; cin >> x; translate[x] = n; }
    
    vector<int> B, C;
    for (int n=0; n<N; ++n) { int x; cin >> x; B.push_back(translate[x]); }
    for (int n=0; n<N; ++n) { int x; cin >> x; C.push_back(translate[x]); }

    vector< pair<int,int> > events(N);
    for (int n=0; n<N; ++n) events[ B[n] ].first = n+1;
    for (int n=0; n<N; ++n) events[ C[n] ].second = n+1;

    size=1;
    while (size<N) size <<= 1;

    long long answer = 0;
    for (int n=0; n<N; ++n) {
        answer += sum( events[n].first, events[n].second );
        add( events[n].first, events[n].second );
    }

    cout << answer << endl;
}
