#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string way, tmp;
    while (cin >> n && n != 0) {
        way = "+x";
        n--;
        while (n--) {
            cin >> tmp;
            if (tmp == "No")
                continue;
            else if(way == "+x")
                way = tmp;
            else if(way == "-x")
            {
                if(tmp[0] == '-')
                {
                    tmp[0] = '+';
                    way = tmp;
                }
                else
                {
                    tmp[0] = '-';
                    way = tmp;
                }
            }
            else if(way[1] == tmp[1]) {
                if(way[0] == tmp[0])
                    way = "-x";
                else
                    way = "+x";
            }
        }
        cout << way << endl;
    }

    return 0;
}