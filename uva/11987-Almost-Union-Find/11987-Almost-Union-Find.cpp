//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

class UFDS {
public:
    vector<int> p, rank, setSizes;
    int numSets;

    UFDS(int N) {
        numSets = N;
        rank.assign(N, 0); p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
        setSizes.assign(N, 1);
    }
    int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                setSizes[x] += setSizes[y]; p[y] = x;
            }
            else {
                setSizes[y] += setSizes[x]; p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
            numSets--;
        }
    }
    int setSize(int i) { return setSizes[findSet(i)]; }
    void clear(){ p.clear(); rank.clear(); setSizes.clear(); }
};/

int main() {
    ios::sync_with_stdio(0);


    return 0;
}
