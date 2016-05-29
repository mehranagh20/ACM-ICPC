#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, i = 0;
    cin >> n;
    while(getchar() != '\n');
    while(i++ != n)
    {
        string s;
        char c;
        while((c = getchar()) != '\n')
            if(isalpha(c))
                s.push_back(tolower(c));
        double sq = sqrt(s.size());
        int sqInt = sq;
        if ((double) sqInt < sq)
            cout << "Case #" << i << ":" << endl << "No magic :(" << endl;
        else {
            bool isMagical = true;
            for (int i = 0; i < s.size() / 2; i++)
                if (s[i] != s[s.size() - i - 1]) {
                    isMagical = false;
                    break;
                }
            if (!isMagical)
                cout << "Case #" << i << ":" << endl << "No magic :(" << endl;
            else {
                vector<vector<char>> arr(sqInt);
                for (int i = 0; i < s.size(); i++)
                    arr[i / sqInt].push_back(s[i]);
                for (int i = 0; i < sqInt; i++) {
                    for (int j = 0; j < sqInt; j++) {
                        if (arr[i][j] != s[(sqInt * i) + j]) {
                            isMagical = false;
                            break;
                        }
                        if (arr[sqInt - i - 1][sqInt - j - 1] != s[(sqInt * i) + j]) {
                            isMagical = false;
                            break;
                        }
                    }
                    if (!isMagical)
                        break;
                }
                if(isMagical)
                    cout << "Case #" << i << ":" << endl << sqInt << endl;
                else
                    cout << "Case #" << i << ":" << endl << "No magic :(" << endl;
            }

        }
    }

    return 0;
}