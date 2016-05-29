#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int caseNum = 0;
    cin >> n;
    while(caseNum != n)
    {
        caseNum++;
        int max = -1;
        int nC;
        cin >> nC;
        while(nC--)
        {
            int speed;
            cin >> speed;
            if(speed > max)
                max = speed;
        }
        cout << "Case " << caseNum << ": " << max <<endl;
    }

     return 0;
}