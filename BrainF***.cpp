#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
   int n, j = 1;
    cin >> n;
    while(getchar() != '\n');
    while(j <= n)
    {
        vector<short int> arr(100, 0);
        char c;
        int i = 0;
        while((c = getchar()) != '\n')
        {
            switch (c)
            {
                case '+':
                    if(++arr[i] > 255)
                        arr[i] = 0;
                    break;
                case '-':
                    if(--arr[i] < 0)
                        arr[i] = 255;
                    break;
                case '>':
                    if(++i > 99)
                        i = 0;
                    break;
                case '<':
                    if(--i < 0)
                        i = 99;
                    break;
                default:
                    break;
            }
        }
        cout << "Case " << dec << j++ << ":";
        for(int i = 0; i < 100; i++) {
            cout << " " <<setfill('0') <<setw(2) << uppercase << hex << arr[i] ;
        }
        cout << endl;
    }

    return 0;
}
