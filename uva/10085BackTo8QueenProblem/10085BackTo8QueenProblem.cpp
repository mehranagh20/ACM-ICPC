#include <bits/stdc++.h>

using namespace std;

bitset<20> row, digL, digR;
vector<vector<int>> solutions;

void solution(int col, vector<int> &tillNow) {
    if(col == 8) {
        solutions.push_back(tillNow);
        return;
    }
    for(int i = 0; i < 8; i++) {
        if(!row[i] && !digR[i - col + 8] && !digL[i + col]) {
            row[i] = 1; digR[i - col + 8] = 1; digL[i + col] = 1;
            tillNow[col] = i;
            solution(col + 1, tillNow);
            row[i] = 0; digR[i - col + 8] = 0; digL[i + col] = 0;
        }
    }
}

int main() {
    vector<int> tillNow(8);
    solution(0, tillNow);
    vector<int> des(8);
    vector<vector<int>> &ss = solutions;
//    for(auto &e : solutions) {
//        for(int i = 0; i < 8; i++) {
//            for(int j = 0; j < 8; j++) {
//                if (e[i] == j)
//                    cout << "1 ";
//                else
//                    cout << "0 ";
//            }
//            cout << endl;
//        }
//        cout << endl << endl;
//    }
    int end = 1;
    while(true) {
        for (int i = 0; i < 8; i++) {
            if(scanf("%d", &des[i]) != EOF) {
                des[i]--;
            }
            else {
                end = 0;
                break;
            }
        }
        if(!end)
            break;
        int ans = 100000;
        for(int i = 0; i < solutions.size(); i++) {
            int thisAns = 0;
            for(int j = 0; j < 8; j++)
                if(des[j] != solutions[i][j])
                    thisAns++;
            if(thisAns < ans)
                ans = thisAns;
        }
        printf("Case %d: %d\n", end++, ans);

    }

    return 0;
}