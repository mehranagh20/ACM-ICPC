#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nCases;
    cin >> nCases;
    while (nCases--) {
        int nJObs, mPrio, time = 0;
        cin >> nJObs >> mPrio;
        queue<pair<int, bool>> jobs;
        vector<int> tmpList(nJObs);
        for (int i = 0; i < nJObs; i++)
            cin >> tmpList[i];
        int tmp = mPrio;
        mPrio = tmpList[mPrio];
        for (int i = 0; i < nJObs; i++) {
            if(i == tmp)
                jobs.push(pair<int, bool>(tmpList[i], true));
            else
                jobs.push(pair<int, bool>(tmpList[i], false));
        }
        sort(tmpList.begin(), tmpList.end());
        while(true)
        {
            if(jobs.front().first == tmpList[nJObs - 1])
            {
                if(jobs.front().second)
                {
                    time++;
                    break;
                }
                time++;
                jobs.pop();
                nJObs--;
            }
            else
            {
                jobs.push(jobs.front());
                jobs.pop();
            }
        }
        cout << time << endl;


    }
    return 0;
}