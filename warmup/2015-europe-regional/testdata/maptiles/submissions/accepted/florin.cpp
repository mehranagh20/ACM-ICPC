#include <iostream>
#include <string>

using namespace std;

int main () {
    string s;
    cin >> s;
    
    long long x = 0, y = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        int p = s.size() - 1 - i;
        
        if (s[i] == '1')
            x += 1LL << p;
        if (s[i] == '2')
            y += 1LL << p;
        if (s[i] == '3') {
            x += 1LL << p;
            y += 1LL << p;
        }
    }
    
    cout << s.size() << " " << x << " " << y << endl;
}