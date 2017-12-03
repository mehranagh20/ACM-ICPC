#include <bits/stdc++.h>
using namespace std;

const long long TOO_MUCH = 1000000000000000001LL;

struct number {
    long long value;
    number(long long value=0) : value(value) {}
    void operator+=(const number &other) {
        value += other.value;
        if (value > TOO_MUCH) value = TOO_MUCH;
    }
    void operator*=(const number &other) {
        double tmp = value;
        tmp *= other.value;
        if (tmp > 3*TOO_MUCH) {
            value = TOO_MUCH;
        } else {
            value *= other.value;
            if (value > TOO_MUCH) value = TOO_MUCH;
        }
    }
};

int main() {
    int R, S, M, D, N;
    cin >> R >> S >> M >> D >> N;
    vector<int> brands(R);
    for (int &x : brands) cin >> x;
    vector< vector<bool> > forbidden( S+M+D, vector<bool>(S+M+D,false) );
    vector< vector<int> > ingredients( S+M+D );
    for (int i=0; i<S+M+D; ++i) { int k; cin >> k; while (k--) { int x; cin >> x; ingredients[i].push_back(x-1); } }
    for (int n=0; n<N; ++n) { int a,b; cin >> a >> b; --a; --b; forbidden[a][b] = forbidden[b][a] = true; }
    number answer = 0;
    for (int s=0; s<S; ++s) {
        for (int m=S; m<S+M; ++m) {
            for (int d=S+M; d<S+M+D; ++d) {
                if (forbidden[s][m]) continue;
                if (forbidden[s][d]) continue;
                if (forbidden[m][d]) continue;
                number current=1;
                set<int> resources;
                for (int x : ingredients[s]) if (!resources.count(x)) { current *= brands[x]; resources.insert(x); }
                for (int x : ingredients[m]) if (!resources.count(x)) { current *= brands[x]; resources.insert(x); }
                for (int x : ingredients[d]) if (!resources.count(x)) { current *= brands[x]; resources.insert(x); }
                answer += current;
            }
        }
    }
    if (answer.value == TOO_MUCH) cout << "too many" << endl; else cout << answer.value << endl;
}
