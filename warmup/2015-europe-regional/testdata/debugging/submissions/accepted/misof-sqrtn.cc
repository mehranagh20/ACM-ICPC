#include <bits/stdc++.h>
using namespace std;

/*
 * An O(n * sqrt(n)) solution
 */

vector<long long> memo;
int N;
long long t_run, t_add;

long long solve(int n) {
    long long &answer = memo[n];
    if (answer >= 0) return answer;
    answer = 1LL << 62;
    if (n == 1) return answer = 0;
    int sqrtn = int( sqrt(n)+1 );

    // try adding 1..sqrtn printfs
    for (long long add = 1; add <= sqrtn; ++add) {
        long long maxpart = (n + add) / (add + 1);
        answer = min( answer, t_add * add + t_run + solve(maxpart) );
    }

    // try splitting into parts of size 1..sqrtn
    for (long long maxpart = 1; maxpart <= sqrtn; ++maxpart) {
        if (maxpart >= n) continue;
        long long add = (n-1) / maxpart;
        answer = min( answer, t_add * add + t_run + solve(maxpart) );
    }
    return answer;
}

int main() {
    cin >> N >> t_run >> t_add;
    memo.resize(N+1,-1);
    cout << solve(N) << endl;
}
