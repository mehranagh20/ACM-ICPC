#include <iostream>
#include <map>

using namespace std;

int main() {
    int i = 1;
    map<string, int> allWords;
    for (char c = 'a'; c <= 'z'; c++) {
        string tmp;
        tmp += c;
        allWords.insert(pair<string, int>(tmp, i++));
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (char c1 = c + 1; c1 <= 'z'; c1++) {
            string tmp = "";
            tmp = c;
            tmp += c1;
            allWords.insert(pair<string, int>(tmp, i++));
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (char c1 = c + 1; c1 <= 'z'; c1++) {
            for (char c2 = c1 + 1; c2 <= 'z'; c2++) {
                string tmp;
                tmp = c ;tmp += + c1; tmp += c2;
                allWords.insert(pair<string, int>(tmp, i++));
            }
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (char c1 = c + 1; c1 <= 'z'; c1++) {
            for (char c2 = c1 + 1; c2 <= 'z'; c2++) {
                for (char c3 = c2 + 1; c3 <= 'z'; c3++) {
                    string tmp;
                    tmp = c; tmp += c1; tmp += c2; tmp += c3;
                    allWords.insert(pair<string, int>(tmp, i++));
                }
            }
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (char c1 = c + 1; c1 <= 'z'; c1++) {
            for (char c2 = c1 + 1; c2 <= 'z'; c2++) {
                for (char c3 = c2 + 1; c3 <= 'z'; c3++) {
                    for (char c4 = c3 + 1; c4 <= 'z'; c4++) {
                        string tmp;
                        tmp = c; tmp += c1; tmp += c2; tmp += c3; tmp += c4;
                        allWords.insert(pair<string, int>(tmp, i++));
                    }
                }
            }
        }
    }
    string str;
    while(getline(cin , str))
    {
        map<string, int>::iterator it;
        if((it = allWords.find(str)) == allWords.end())
            cout << "0" << endl;
        else
            cout << it->second << endl;
    }

    return 0;
}