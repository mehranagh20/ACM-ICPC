#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        if(n == 1)
        {
            cout << "Printing order for 1 pages:\n"
                            "Sheet 1, front: Blank, 1" << endl;
            continue;
        }
        cout << "Printing order for " << n << " pages:" << endl;
        int max = n / 4;
        if(n % 4)
            max++;
        max *= 4;
        vector<int> hlp(max);
        if(max - n == 3) {
            hlp[0] = -1;
            hlp[3] = -1;
            hlp[4] = -1;
        }
        if(max - n == 2) {
            hlp[0] = -1;
            hlp[3] = -1;
        }
        if(max - n == 1)
            hlp[0] = -1;
        int tmp = 1, tmp2 = n;
        bool bigFirst = false;
        for(int i = 0; i < max; i++)
        {
            if(!bigFirst) {
                if (hlp[i] != -1)
                    hlp[i] = tmp2--;
                if(hlp[i + 1] != -1)
                    hlp[i + 1] = tmp++;
            }
            else
            {
                if (hlp[i + 1] != -1)
                    hlp[i + 1] = tmp2--;
                if(hlp[i] != -1)
                    hlp[i] = tmp++;
            }
            i++;
            bigFirst = !bigFirst;
        }
        for(int i = 0; i < max; i++)
        {
            cout << "Sheet " << i / 4 + 1 << ", " << "front: ";
            if(hlp[i] == -1)
                cout << "Blank, ";
            else
                cout << hlp[i] << ", ";
            cout << hlp[i + 1] << endl;
            cout << "Sheet " << i / 4 + 1 << ", " << "back : ";
            cout << hlp[i + 2] << ", ";
            if(hlp[i + 3] == -1)
                cout << "Blank" << endl;
            else
                cout << hlp[i + 3] << endl;
            i += 3;
        }
    }

    return 0;
}