#include <iostream>
#include <string>

using namespace std;

int main() {
  int nPar, budget, nHotels, nWeaks;
    while((cin >> nPar >> budget >> nHotels >> nWeaks))
    {
        int min = 100000000;
        for(int i = 0; i < nHotels; i++) {
            int x;
            cin >> x;
            int nBeds;
            for(int j = 0; j < nWeaks; j++)
            {
                cin >> nBeds;
                if(nBeds >= nPar && nPar * x < min) {
                    min = nPar * x;
                    string tm;
                    getline(cin, tm);
                    break;
                }
            }
        }
        if(min == 100000000 || min > budget)
            cout << "stay home" << endl;
        else
            cout << min << endl;


    }
    return 0;
}