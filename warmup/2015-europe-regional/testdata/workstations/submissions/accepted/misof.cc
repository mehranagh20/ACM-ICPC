#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector< pair<int,int> > requests;
    for (int n=0; n<N; ++n) { int a,b; cin >> a >> b; requests.push_back({a,a+b}); }
    sort( requests.begin(), requests.end() );
    int answer = 0;
    multiset<int> available;
    for (auto r : requests) {
        while (!available.empty() && *available.begin()+M < r.first) available.erase( available.begin() );
        if (!available.empty() && *available.begin() <= r.first) {
            ++answer;
            available.erase( available.begin() );
        }
        available.insert( r.second );
    }
    cout << answer << endl;
}
