#include <stdio.h>
#include <list>

using namespace std;

int main() {
    char c;
    list<char>::iterator i;
    bool end = true;
    list<char> list1;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (c == '[') {
                end = false;
                i = list1.begin();
            }
            else if (c == ']')
                end = true;
            else {
                if (end)
                    list1.push_back(c);
                else {
                    list1.insert(i, c);
                }
            }
        }
        else {
            i = list1.begin();
            for(i; i != list1.end(); i++)
                printf("%c", *i);
            puts("");
            list1.clear();
        }
    }

}
