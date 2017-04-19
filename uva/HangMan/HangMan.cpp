#include <iostream>
#include <map>

using namespace std;

int main()
{
    int round;
    while(cin >> round && round != -1)
    {
        int rightGuessed = 0, wrongGuessed = 0;
        while(getchar() != '\n');
        map <char, bool> word;
        map <char, bool> inserted;
        char c;
        while((c = getchar()) != '\n')
        {
            word.insert(pair<char, bool>(c, false));
        }
        while((c = getchar()) != '\n')
        {
            if(word.find(c) == word.end()) //not found
            {
                if(inserted.find(c) == inserted.end()) {
                    if (++wrongGuessed >= 7) {
                        while (getchar() != '\n');
                        break;
                    }
                    inserted.insert(pair<char, bool>(c, true));
                }
            }
            else if(!word[c])
            {
                if(++rightGuessed == word.size()){
                    while(getchar() != '\n');
                    break;
                }
                word[c] = true;
            }
        }
        cout << "Round " << round << endl;
        if(wrongGuessed >= 7)
            cout << "You lose." << endl;
        else if(rightGuessed == word.size())
            cout << "You win." << endl;
        else
            cout << "You chickened out." << endl;
    }

    return 0;
}