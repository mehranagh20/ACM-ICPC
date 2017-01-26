#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, i = 0;
    vector<int> arr;
    while(cin >> n)
    {
        i++;
        if(i > 1)
        {
            vector<int> tmp;
            int i = 0;
            for(i; i < arr.size(); i++) {
                if (arr[i] < n)
                    tmp.push_back(arr[i]);
                else
                    break;
            }
            tmp.push_back(n);
            for(i; i < arr.size(); i++)
                tmp.push_back(arr[i]);
            arr = tmp;
        }
        else
            arr.push_back(n);
        if(i % 2)
            cout << arr[(i / 2)] << endl;
        else
            cout << (arr[i / 2 - 1] + arr[i / 2]) / 2 << endl;
    }

    return 0;
}
