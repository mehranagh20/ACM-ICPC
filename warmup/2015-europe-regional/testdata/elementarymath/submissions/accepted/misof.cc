#include <bits/stdc++.h>
using namespace std;

struct MaximumMatching {
    vector< vector<int> > left_to_right, right_to_left;
    MaximumMatching(int LS, int RS) { left_to_right.resize(LS); right_to_left.resize(RS); }

    void add_edge(int left, int right);
    vector< pair<int,int> > maximum_matching();
};

void MaximumMatching::add_edge(int left, int right) {
    left_to_right[left].push_back(right);
    right_to_left[right].push_back(left);
}

vector< pair<int,int> > 
MaximumMatching::maximum_matching() {
    int L = left_to_right.size(), R = right_to_left.size();
    vector<int> match(L,-1);
    for (int r=0; r<R; r++) {
        bool found = false;
        vector<int> from(L,-1);
        queue<int> Q;
        for (auto l : right_to_left[r]) { Q.push(l); from[l]=l; }
        while (!Q.empty() && !found) {
            int l = Q.front(); Q.pop();
            if (match[l]==-1) {
                found = true;
                while (from[l]!=l) { match[l] = match[from[l]]; l = from[l]; }
                match[l]=r;
            } else {
                for( auto ll : right_to_left[ match[l] ] ) if (from[ll] == -1) { Q.push(ll); from[ll] = l; }
            }
        }
    }
    vector< pair<int,int> > result;
    for (int i=0; i<L; i++) if (match[i] != -1) result.push_back(make_pair(i,match[i]));
    return result;
}

int main() {
    int N;
    cin >> N;
    
    vector< vector<long long> > G(N);
    vector<long long> A, B;
    set<long long> right_options;

    for (int n=0; n<N; ++n) {
        long long a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        right_options.insert( a+b );
        right_options.insert( a-b );
        right_options.insert( a*b );
    }

    vector<long long> right_value( right_options.size() );
    map<long long, int> right_id;
    int next_id = 0;
    for (auto x : right_options) {
        right_id[x] = next_id;
        right_value[next_id] = x;
        ++next_id;
    }

    MaximumMatching MM ( N, right_options.size() );
    for (int n=0; n<N; ++n) {
        auto a = A[n], b = B[n];
        MM.add_edge( n, right_id[a+b] );
        MM.add_edge( n, right_id[a-b] );
        MM.add_edge( n, right_id[a*b] );
    }

    auto matching = MM.maximum_matching();
    if (matching.size() < N) {
        cout << "impossible" << endl;
        return 0;
    }

    sort( matching.begin(), matching.end() );
    for (int n=0; n<N; ++n) {
        long long a = A[n], b = B[n];
        long long c=a+b, d=a-b, e=a*b;
        long long wanted = right_value[ matching[n].second ];
        if (c == wanted) { cout << a << "+" << b << "=" << wanted << endl; continue; }
        if (d == wanted) { cout << a << "-" << b << "=" << wanted << endl; continue; }
        if (e == wanted) { cout << a << "*" << b << "=" << wanted << endl; continue; }
    }
}
