#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n <= 1) {
            cin >> n;
            cout << "Jolly" << endl;
        }
        else {
            bitset<3000> bits;
            int a, b;
            cin >> a;
            for (int i = 0; i < n - 1; i++) {
                cin >> b;
                if (a == b || abs(a - b) > n) {
                    string str;
                    getline(cin, str);
                    break;
                }
                bits.set(abs(b - a) - 1, 1);
                a = b;
            }
            bitset<3000> tmp = 1;
            for(int i = 0; i < n - 2; i++)
            {
                tmp <<= 1;
                tmp |= 1;
            }
            if ((tmp == bits))
                cout << "Jolly" << endl;
            else
                cout << "Not jolly" << endl;
        }
    }
    return 0;
}

