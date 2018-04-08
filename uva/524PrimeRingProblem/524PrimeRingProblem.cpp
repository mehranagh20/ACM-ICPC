#include <bits/stdc++.h>

using namespace std;

int used[17], n;
vector<int> s;

bool isPrime(int a) {
    if (!(a % 2))
        return false;
    for (int i = 3; i * i <= a; i += 2)
        if (!(a % i))
            return false;
    return true;
}

void solution(int numTillNow) {
    if (numTillNow == n) {
        if (!isPrime(s[1] + s[s.size() - 1]))
            return;
        printf("%d", s[1]);
        for (int i = 2; i < s.size(); i++)
            printf(" %d", s[i]);
        puts("");
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!used[i] && isPrime(i + s[numTillNow])) {
            used[i] = 1;
            s[numTillNow + 1] = i;
            solution(numTillNow + 1);
            used[i] = 0;
        }
    }
}

int main() {
    int caseNum = 1;
    while (scanf("%d", &n) != EOF) {

        if (caseNum > 1)
            puts("");
        printf("Case %d:\n", caseNum++);
        s.resize(n + 1);
        memset(used, 0, (n + 1) * sizeof(int));
        used[1] = true;
        s[1] = 1;
        solution(1);
    }

    return 0;
}