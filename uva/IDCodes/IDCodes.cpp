#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    while(getline(cin, str) && str != "#")
    {
        int i = 0;
        while(next_permutation(str.begin(), str.end()))
        {
            i++;
            cout << str << endl;
            break;
        }
        if(!i)
            cout << "No Successor" << endl;
    }

    return 0;
}
