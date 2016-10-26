#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> seq;
int currInd = -1, firstInd = 1e9;

bool binSearch(char c) {
    vector<int> &tmpV = seq[c];
    int low = 0, high = seq[c].size(), mid, ans = currInd;
    while (abs(high - low) >= 1) {
        mid = (low + high) / 2;
        if (tmpV[mid] > currInd) {
            ans = tmpV[mid];
            high = mid;
        }
        else
            low = mid + 1;
    }
    if (ans < firstInd)
        firstInd = ans;
    bool poss = (currInd == ans); currInd = ans;
    if(poss) return false;
    return true;
}

int main() {
    seq.resize(123);
    vector<vector<int>> &s = seq;
    char c;
    int i = 0, q;
    while ((c = getchar()) != '\n')
        seq[c].push_back(i++);
    scanf("%d", &q);
    while (getchar() != '\n');
    while (q--) {
        string s;
        getline(cin, s);
        bool possible = true;
        for (auto &c : s) {
            if (!binSearch(c)) {
                possible = false;
                break;
            }
        }
        if (possible) printf("Matched %d %d\n", firstInd, currInd);
        else printf("Not matched\n");
        currInd = -1;
        firstInd = 1e9;
    }

    return 0;
}