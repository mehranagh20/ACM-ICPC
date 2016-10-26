#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int nSta, carierM, queM, maxCago = 0, doneUntilNow = 0, timeTillNow = 0, cI = 1;
        cin >> nSta >> carierM >> queM;
        stack<int> carier;
        vector<queue<int>> platB(nSta  + 1);
        for (int i = 1; i < nSta + 1; i++) {
            int maxCargoHere;
            cin >> maxCargoHere;
            maxCago += maxCargoHere;
            for (int j = 0; j < maxCargoHere; j++) {
                int tmp;
                cin >> tmp;
                platB[i].push(tmp);
            }
        }
        while (doneUntilNow != maxCago) {
            while (!carier.empty() && carier.top() == cI) {
                timeTillNow++;
                doneUntilNow++;
                carier.pop();
            }
            while (!carier.empty() && platB[cI].size() < queM) {
                platB[cI].push(carier.top());
                carier.pop();
                while (!carier.empty() && carier.top() == cI) {
                    timeTillNow++;
                    doneUntilNow++;
                    carier.pop();
                }
                timeTillNow++;
            }
            while(!platB[cI].empty() && carier.size() < carierM)
            {
                carier.push(platB[cI].front());
                platB[cI].pop();
                timeTillNow++;
            }
            cI++;
            if(cI == nSta + 1)
                cI = 1;
            if(doneUntilNow != maxCago)
                timeTillNow += 2;
        }
        cout << timeTillNow << endl;
    }
    return 0;
}