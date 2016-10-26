#include <iostream>

using namespace std;

int main()
{
    unsigned n, fN, sN;
    cin >> n;
    while(n--)
    {
        cin >> fN >> sN;
        if(sN > fN)
            cout << "impossible" << endl;
        else {
            double tmp = (double)(fN + sN) / 2;
            unsigned hlp = tmp;
            if((double)hlp < tmp)
                cout << "impossible" << endl;
            else
            {
                cout << hlp << " " << fN - hlp << endl;
            }
        }
    }

    return 0;
}