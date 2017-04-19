#include <iostream>
using namespace std;

int main() {
   int k;
   cin >> k;
    while(k != 0)
    {
        int x, y ;
        cin >> x >> y;
        while(k--)
        {
            int a, b;
            cin >> a >> b;
            if(a == x || b == y)
                cout << "divisa" << endl;
            else if(a > x && b > y)
                cout << "NE" << endl;
            else if(a > x && b < y)
                cout << "SE" << endl;
            else if(a < x && b > y)
                cout << "NO" << endl;
            else if(a < x && b < y)
                cout << "SO" <<endl;
        }
        cin >> k;
    }
    return 0;
}