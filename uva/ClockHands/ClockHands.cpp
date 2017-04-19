#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s) && s != "0:00")
    {
        string::size_type sz;
        double t1 = stod(s, &sz); sz++; double t2 = stod(s.substr(sz));
        t1 *= 5;
        t1 += (t2 / 12);
        double sub;
        if(t1 > t2)
            sub = t1 - t2;
        else
            sub = t2 - t1;
        sub /= 5;
        sub *= 30;
        if(sub > 180)
            sub = 360 - sub;
        cout << setprecision(3) << fixed << sub << endl;
    }

    return 0;
}