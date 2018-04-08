#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    vector<int> qu;
    while (cin >> n && n) {
        for (int i = qu.size(); i < n; i++)
            qu.push_back(i + 1);
        int tmp;
        while (cin >> tmp && tmp) {
            stack<int> station;
            bool isPos = true;
            int i = 0;
            while (qu[i] != tmp)
                station.push(qu[i++]);
            i++;
            for (int j = 0; j < n - 1; j++) {
                cin >> tmp;
                if (!station.empty() && station.top() == tmp)
                    station.pop();
                else if(tmp < qu[i] || i >= n)
                {
                    isPos = false;
                    for(int k = j + 1; k < n - 1; k++)
                        cin >> tmp;
                    break;
                }
                else {
                    while (qu[i] != tmp) {
                        station.push(qu[i++]);
                    }
                    i++;
                }
            }
            if (isPos)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
}
