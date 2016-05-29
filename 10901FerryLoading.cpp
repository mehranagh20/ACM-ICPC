#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int nCases;
    cin >> nCases;
    int i = 0;
    while (nCases--) {
        if (i++ > 0)
            cout << endl;
        int fCap, carsIn = 0, timeReq, carsNum, i = 0, currTime = 0;
        cin >> fCap >> timeReq >> carsNum;
        char currSide = 'l';
        vector<int> order(carsNum);
        queue<pair<int, int>> rightQ;
        queue<pair<int, int>> leftQ;
        while (carsNum--) {
            int arrTime;
            cin >> arrTime;
            getchar();
            string str;
            getline(cin, str);
            if (str == "left")
                leftQ.push(pair<int, int>(arrTime, i++));
            else
                rightQ.push(pair<int, int>(arrTime, i++));
        }
        while (!rightQ.empty() || !leftQ.empty()) {
            if (currSide == 'l') {
                while (!leftQ.empty() && leftQ.front().first <= currTime && carsIn < fCap) {
                    carsIn++;
                    order[leftQ.front().second] = currTime + timeReq;
                    leftQ.pop();
                    currSide = 'r';
                }
                if (carsIn == 0) {
                    if (leftQ.empty() || (rightQ.front().first < leftQ.front().first && !rightQ.empty())) {
                        if (rightQ.front().first > currTime)
                            currTime = rightQ.front().first;
                        currSide = 'r';
                    }
                    else if (leftQ.front().first <= rightQ.front().first || rightQ.empty()) {
                        currTime = leftQ.front().first;
                        continue;
                    }
                }
            }
            else {
                while (!rightQ.empty() && rightQ.front().first <= currTime && carsIn < fCap) {
                    carsIn++;
                    order[rightQ.front().second] = currTime + timeReq;
                    rightQ.pop();
                    currSide = 'l';
                }
                if (carsIn == 0) {
                    if (rightQ.empty() || (rightQ.front() > leftQ.front() && !leftQ.empty())) {
                        if (currTime < leftQ.front().first)
                            currTime = leftQ.front().first;
                        currSide = 'l';
                    }
                    else if (leftQ.front().first >= rightQ.front().first || leftQ.empty()) {
                        currTime = rightQ.front().first;
                        continue;
                    }
                }
            }
            currTime += timeReq;
            carsIn = 0;
        }
        for (auto &e : order)
            cout << e << endl;
    }

    return 0;
}