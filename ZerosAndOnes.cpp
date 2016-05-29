#include <iostream>
#include <string>

using namespace std;

int main() {
   string input;
    int caseNum = 0;
    while(cin >> input)
    {
        caseNum++;
        if(input == "")
            break;
        int i, j, n;
        cin >> n;
        cout << "Case " << caseNum << ":" << endl;
        while(n--)
        {
            bool isYes = true;
            cin >> i >> j;
            if(i > j)
            {
                int tmp = i;
                i = j;
                j = tmp;
            }
            string tmpStr = input.substr(i, j - i + 1);
            size_t n1 = tmpStr.find('0');
            size_t n2 = tmpStr.find('1');
            if(input[i] == '0') {
                if (n2 != string::npos)
                    isYes = false;
            }
            else
                if(n1 != string::npos)
                    isYes = false;
            if(isYes)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}