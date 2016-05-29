#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, j = 0;
    while(cin >> n)
    {
        if(j++ > 0)
            cout << endl;
        vector<string> order;
        map<string, int> data;
        string tmpStr;
        int i = 0;
        while(i != n)
        {
            cin >> tmpStr;
            order.push_back(tmpStr);
            pair<string, int> tmpPair (tmpStr, 0);
            data.insert(tmpPair);
            i++;
        }
        i = 0;
        while(i != n)
        {
            int mon, numOfFr;
            cin >> tmpStr>> mon >> numOfFr;
            if(numOfFr == 0)
            {
                i++;
                continue;
            }
            int gift = mon / numOfFr;
            data[tmpStr] -= (numOfFr * gift);
            while(numOfFr--)
            {
                cin >> tmpStr;
                data[tmpStr] += gift;
            }
            i++;
        }
        for(auto & el : order)
        {
            cout << el << " " <<data[el] << endl;
        }
    }

    return 0;
}