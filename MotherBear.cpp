#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(true) {
        string s, s2;
        char c;
        while ((c = getchar()) != '\n') {
            s2.push_back(c);
            if(isalpha(c))
                s.push_back(tolower(c));
        }
        if(s2 == "DONE")
            break;
        bool isPol = true;
        for(int i = 0; i < s.size() / 2; i++)
            if(s[i] != s[s.size() - i - 1])
            {
                isPol = false;
                break;
            }
        if(isPol)
            cout << "You won't be eaten!" << endl;
        else
            cout << "Uh oh.." << endl;
    }
    return 0;
}