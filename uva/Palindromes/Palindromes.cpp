#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, char> revList;
void calRev()
{
    revList.insert(pair<char, char>('A', 'A'));
    revList.insert(pair<char, char>('E', '3'));
    revList.insert(pair<char, char>('H', 'H'));
    revList.insert(pair<char, char>('I', 'I'));
    revList.insert(pair<char, char>('J', 'L'));
    revList.insert(pair<char, char>('L', 'J'));
    revList.insert(pair<char, char>('M', 'M'));
    revList.insert(pair<char, char>('O', 'O'));
    revList.insert(pair<char, char>('S', '2'));
    revList.insert(pair<char, char>('T', 'T'));
    revList.insert(pair<char, char>('U', 'U'));
    revList.insert(pair<char, char>('V', 'V'));
    revList.insert(pair<char, char>('W', 'W'));
    revList.insert(pair<char, char>('X', 'X'));
    revList.insert(pair<char, char>('Y', 'Y'));
    revList.insert(pair<char, char>('Z', '5'));
    revList.insert(pair<char, char>('1', '1'));
    revList.insert(pair<char, char>('2', 'S'));
    revList.insert(pair<char, char>('3', 'E'));
    revList.insert(pair<char, char>('5', 'Z'));
    revList.insert(pair<char, char>('8', '8'));
}

bool isMirrored(string &s)
{
    bool a = revList.find(s[s.size() / 2]) == revList.end();
    bool b = revList[s[s.size()/2]] != s[s.size() / 2];
    if(s.size() % 2 && (a || b))
        return false;
    for(int i = 0; i < s.size() / 2; i++)
    {
        if(revList.find(s[i]) ==revList.end() || revList[s[i]] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

bool isPol(string &s)
{
    for(int i = 0; i < s.size() / 2; i++)
        if(s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

int main()
{
    calRev();
    string s;
    while(cin >> s)
    {
        bool pol = isPol(s);
        bool mir = isMirrored(s);
        if(!(pol || mir))
            cout << s << " -- is not a palindrome." << endl;
        if (pol && !mir)
            cout << s << " -- is a regular palindrome." << endl;
        if (mir && !pol)
            cout << s << " -- is a mirrored string." << endl;
        if(pol && mir)
            cout << s << " -- is a mirrored palindrome." << endl;
        cout << endl;
        while(getchar() != '\n');
    }

    return 0;
}