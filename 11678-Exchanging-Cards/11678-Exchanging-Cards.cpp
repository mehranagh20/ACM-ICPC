#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int n; int m;
    while (cin >> n >> m){
        if (n == 0 && m == 0){
            return 0;
        }
        vector <int> v1;
        for (int i = 0 ; i < n ; i++){
            int temp; cin >> temp; v1.push_back(temp);
        }
        vector <int> v2;
        for (int i = 0 ; i < m ; i++){
            int temp; cin >> temp; v2.push_back(temp);

        }

        auto it = unique(v1.begin(), v1.end());
        auto it2 = unique(v2.begin(), v2.end());

        int avail1 = 0; int avail2 = 0;
        for (int i = 0 ; i <  it  - v1.begin (); i++){
            int card = v1[i];
            if (binary_search(v2.begin(), v2.end(), card) == false) avail1++;
        }
        for (int i = 0 ; i <  it2 - v2.begin () ; i++){
            int card = v2[i];
            if (binary_search(v1.begin(), v1.end(), card) == false) avail2++;
        } cout << min (avail1 , avail2) << endl;
    }

    return 0;
}