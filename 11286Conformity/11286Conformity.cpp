#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int max = 0;
        vector<int> tmp(5);
        map<vector<int>, int> freq;
        int hlp = n;
        while (hlp--) {
            for (int i = 0; i < 5; i++) {
                cin >> tmp[i];
            }
            sort(tmp.begin(), tmp.end());
            if(freq.find(tmp) == freq.end())
                freq.insert(pair<vector<int>, int>(tmp, 1));
            else {
                freq[tmp]++;
                if(freq[tmp] > max)
                    max = freq[tmp];
            }
        }
        hlp = max;
        max = 0;
        for(map<vector<int>, int>::iterator it = freq.begin(); it != freq.end(); it++)
            if(it->second == hlp)
                max += hlp;
        if(max)
        cout << max << endl;
        else
            cout << n << endl;
    }

    return 0;
}