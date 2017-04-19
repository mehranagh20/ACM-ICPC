#include <iostream>

using namespace std;

int main() {
    int l;
    while(cin >> l && l != 0) {
        while (getchar() != '\n');
        char currChar = 0;
        int dis = 0, min = 10000000;
        while(l--)
        {
            char pos = getchar();
            if(isalpha(pos))
            {
                if(pos == 'Z') {
                    min = 0;
                    break;
                }
                if(currChar == 0) {
                    currChar = pos;
                    dis = 0;
                }
                else
                {
                    if(pos == currChar)
                        dis = 0;
                    else
                    {
                        currChar = pos;
                        if(min > dis)
                            min = dis;
                        dis = 0;
                    }

                }
            }
            dis++;
        }
        cout << min << endl;
        while(getchar() != '\n');
    }

    return 0;
}