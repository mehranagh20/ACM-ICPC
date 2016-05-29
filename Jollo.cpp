#include <iostream>
#include <algorithm>

using namespace std;

int points[5];
int chooseTheBest(int des)
{
    for(des; des < 53; des++)
    {
        bool hlp = false;
        for(int i = 0; i < 5 ; i++)
            if(des == points[i])
                break;
            else if(i == 4)
                hlp = true;
        if(hlp)
            return des;
    }
    return -1;
}

int main()
{
    while(cin >> points[0] >> points[1] >> points[2] >> points[3] >> points[4] && points[0] != 0)
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 2; j++)
                if(points[j] > points[j + 1])
                    swap(points[j], points[j + 1]);
        bool sit[5] = {false, false, false, false, false};
        for(int i = 3; i < 5; i++)
            for(int j = 0; j < 3; j++)
                if((points[j] > points[i]) && !sit[j])
                {
                    sit[i] = true;
                    sit[j] = true;
                    break;
                }
        if(sit[3] && sit[4]) //won already
        {
            cout << "-1" << endl;
        }
        else if(!(sit[3] || sit[4])) //lost already
        {
            cout << chooseTheBest(1) << endl;
        }
        else //choose the best card
        {
            int loser, winner;
            if(sit[3])
            {
                loser = 3;
                winner = 4;
            }
            else
            {
                loser = 4;
                winner = 3;
            }
            sit[0] = false; sit[1] = false; sit[2] = false;
            for(int i = 0; i < 3; i++)
                if(points[loser] < points[i]) {
                    sit[i] = true;
                    break;
                }
            for(int i = 0; i < 3; i++)
                if((points[winner] > points[i]) && !sit[i]) {
                    sit[i] = true;
                    break;
                }
            for(int i = 0; i < 3; i++)
                if(!sit[i])
                {
                    cout << chooseTheBest(points[i]) << endl;
                    break;
                }
        }

    }

    return 0;
}