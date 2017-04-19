#include <iostream>
#include <string>

using namespace std;

int main() {
    string digits;
    int lvl, currNum;
    while (getline(cin, digits)) {
        lvl = 0;
        if (digits == "END")
            break;
        currNum = digits.size();
        lvl++;
        while(digits != to_string(currNum))
        {
            lvl++;
            digits = to_string(currNum);
            currNum = digits.size();
        }
        cout << lvl <<endl;
    }

    return 0;
}