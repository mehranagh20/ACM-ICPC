#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator()(pair<pair<int, int>, int> &l, pair<pair<int , int>, int> &r) {
        if (l.first.first != r.first.first)
            return l.first > r.first;
        else
            return l.second > r.second;
    }
};

int main() {
    string str;
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> prio;
    cin >> str;
    while(str != "#") {
        int id, period;
        cin >> id >> period;
        prio.push(pair<pair<int, int>, int>(pair<int, int>(period, period), id));
        while(getchar() != '\n');
        cin >> str;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cout << prio.top().second << endl;
        pair<pair<int, int>, int> tmp = prio.top();
        tmp.first.first += tmp.first.second;
        prio.pop();
        prio.push(tmp);
    }
    return 0;
}