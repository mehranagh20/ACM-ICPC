#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--)
    {
        map<char, int> valT;
        int nChar;
        cin >> nChar;
        while(nChar--)
        {
            char tmp;
            int val;
            cin >> tmp >> val;
            valT.insert(pair<char, int>(tmp, val));
        }
        int nLine;
        cin >> nLine;
        while(getchar() != '\n');
        int totalVal = 0;
        while(nLine--)
        {
            char tmp;
            while((tmp = getchar()) != '\n')
                if(valT.find(tmp) != valT.end())
                    totalVal += valT[tmp];
        }
        cout << setprecision(2) << fixed << setw(0) << (double)totalVal / 100 << "$" << endl;
    }

    return 0;
}
