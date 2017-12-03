#include <bits/stdc++.h>
using namespace std;

bool done[210][210];
int memo[210][210];

int solve(int P, int B, const vector< pair<int,int> > &blbci) {
    int &res = memo[P][B];
    if (done[P][B]) return res;
    done[P][B] = true;
    if (P==0 && B==0) return res = 0;
    if (P==0 && B>0) return res = -123456789;
    if (P>0 && B==0) return res = -123456789;
    res = -123456789;
    for (int last=1; last<=B; ++last) {
        int last_arrive = blbci[B-1].first;
        int first_leave = blbci[B-last].second;
        if (first_leave <= last_arrive) break;
        res = max( res, first_leave - last_arrive + solve( P-1, B-last, blbci ) );
    }
    return res;
}

int main() {
    int N, P; cin >> N >> P;

    vector< pair<int,int> > workeri;
    for (int n=0; n<N; ++n) { int a, b; cin >> a >> b; workeri.push_back( {a,b} ); }

    vector< pair<int,int> > blbci, borci;
    for (int n=0; n<N; ++n) {
        bool blbec = true;
        for (int a=0; a<n; ++a) if (workeri[n].first <= workeri[a].first && workeri[a].second <= workeri[n].second) blbec = false;
        for (int a=n+1; a<N; ++a) if (workeri[n].first <= workeri[a].first && workeri[a].second <= workeri[n].second && workeri[a] != workeri[n]) blbec = false;
        if (blbec) {
            blbci.push_back( workeri[n] );
        } else {
            borci.push_back( workeri[n] );
        }
    }

    sort( blbci.begin(), blbci.end() );
    sort( borci.begin(), borci.end(), [](const pair<int,int> &a, const pair<int,int> &b) { return a.second-a.first > b.second-b.first; } );

    int BLC = blbci.size(), BRC = borci.size();

    int answer = 0;

    for (int liniek_borcov = 0; liniek_borcov <= BRC && liniek_borcov < P; ++liniek_borcov) {
        int curr = 0;
        for (int i=0; i<liniek_borcov; ++i) curr += borci[i].second - borci[i].first;
        curr += solve( P-liniek_borcov, BLC, blbci );
        answer = max( answer, curr );
    }
    cout << answer << endl;
}
