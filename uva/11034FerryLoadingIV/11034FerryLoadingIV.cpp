#include <iostream>
#include <queue>

using namespace std;

int main() {
    int nCases;
    cin >> nCases;
    while(nCases--)
    {
        int fL, nCars, remainedSpot, numOfCrosses = 0;
        char currSide = 'l';
        queue<int> left, right;
        cin >> fL >> nCars;
        fL *= 100;
        remainedSpot = fL;
        while(nCars--)
        {
            int carL;
            cin >> carL;
            string str;
            getchar();
            getline(cin, str);
            if(str == "left")
                left.push(carL);
            else
                right.push(carL);
        }
        while(!right.empty() || !left.empty())
        {
            if(currSide == 'l')
            {
                while(!left.empty() && remainedSpot >= left.front())
                {
                    remainedSpot -= left.front();
                    left.pop();
                }
                currSide = 'r';
            }
            else
            {
                while(!right.empty() && remainedSpot >= right.front())
                {
                    remainedSpot -= right.front();
                    right.pop();
                }
                currSide = 'l';
            }
            remainedSpot = fL;
            numOfCrosses++;
        }
        cout << numOfCrosses << endl;
    }
    return 0;
}