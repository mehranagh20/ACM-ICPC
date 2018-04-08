#include <stdio.h>
#include <list>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    while(n--) {
        list<pair<unsigned long int, unsigned long int>> list1 = {{0, 1}, {1, 1}, {1, 0}};
        list<pair<unsigned long int, unsigned long int>>::iterator it = list1.begin();
        it++;
        char c;
        while ((c = getchar()) != '\n') {
            if (c == 'R') {
                auto tmpIt = it;
                unsigned long int a = (*(++tmpIt)).first + (*(it)).first , b = (*(tmpIt)).second + (*(it)).second;
                list1.insert(tmpIt, make_pair(a, b));
                it++;
            }
            else {
                auto tmpIt = it;
                unsigned long int a = (*(tmpIt)).first + (*(--it)).first , b = (*(tmpIt)).second + (*(it)).second;
                list1.insert(tmpIt, make_pair(a, b));
                ++it;
            }
        }
        printf("%lu/%lu\n", (*it).first, (*it).second);
    }

    return 0;
}