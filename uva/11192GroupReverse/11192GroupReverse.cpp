#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    while(cin >> n && n)
    {
        string str;
        getline(cin, str);
        str = str.substr(1);
        int size = str.size() / n;
        for(int i = 0; i < n; i++) {
            int j = i * size + size;
            for (j; j > i * size; j--) {
                cout << str[j - 1];
            }
        }
        cout << endl;
    }

    return 0;
}
