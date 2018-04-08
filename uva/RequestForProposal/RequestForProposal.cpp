#include <iostream>
#include <string>

using namespace std;

int main() {
    int req, nP, met, temp2, testCase = 0;
    double price, temp1;
    while(cin >> req >> nP && (req != 0 || nP != 0)) {
        if(testCase > 0)
            cout << endl;
        testCase++;
        met = -1;
        price = 10000000;
        string tmp, acc;
        while ((req--) + 1)
            getline(cin, tmp);
        while (nP--) {
            getline(cin, tmp);
            cin >> temp1 >> temp2;
            if (temp2 > met || (met == temp2 && temp1 < price)) {
                acc = tmp;
                met = temp2;
                price = temp1;
            }
            while ((temp2--) + 1)
                getline(cin, tmp);
        }
        cout << "RFP #" << testCase << endl << acc <<endl;
    }
    return 0;
}