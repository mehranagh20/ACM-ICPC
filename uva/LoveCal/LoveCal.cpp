#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int calSumOfDigit(int num)
{
    while(num / 10 > 0)
    {
        string tmp = to_string(num);
        num = 0;
        for(auto & d : tmp)
            num += d - 48;
    }
    return num;
}

int main() {// a assci code is 97
    string fN, sN;
    while(getline(cin, fN) && getline(cin, sN))
    {
        int num1 = 0, num2 = 0;
        for(auto & c : fN)
            if(isalpha(c))
                num1 += tolower(c) - 96;
        for(auto & c : sN)
            if(isalpha(c))
                num2 += tolower(c) - 96;
        double ans;
        if(num1 == 0)
        {
            cout << "0.00 %" << endl;
            continue;
        }
        num1 = calSumOfDigit(num1);
        num2 = calSumOfDigit(num2);
        if(num1 < num2)
            ans = ((double)num1 / num2) * 100;
        else
            ans = ((double)num2 / num1) * 100;
        cout << setprecision(2) << fixed << ans << " %" << endl;

    }

    return 0;
}