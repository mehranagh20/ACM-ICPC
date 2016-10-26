#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        int nWalls, numOfB = 0, numOfL = 0;
        cin >> nWalls;
        if(nWalls == 0)
            cout << "0 0" << endl;
        else {
            int num;
            cin >> num; nWalls--;
            while(nWalls--) {
                int tmp;
                cin >> tmp;
                if(tmp > num)
                    numOfB++;
                else if(tmp < num)
                    numOfL++;
                num = tmp;
            }
            cout << numOfB << " " << numOfL << endl;
        }
    }

    return 0;
}

