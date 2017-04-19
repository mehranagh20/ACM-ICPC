#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n, i = 1;
    while(cin >> n && n != 0)
    {
        cout << "Case " << i++ << ":" << endl;
        int sum = 0, tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            sum += tmp;
        }
        if(!(sum % n)) {
            if (sum < 0)
                cout << "- ";
            cout << abs(sum) / n << endl;
        }
        else
        {
            if(sum == 0) {
                cout << "0" << endl;
                continue;
            }
            int nSpa = 0;
            if(sum < 0)
                nSpa += 2;
            int up = sum % n;
            int bef = sum / n;
            int gc = gcd(abs(n), abs(up));
            n /= gc;
            up /= gc;
            if(bef)
                nSpa += to_string(abs(bef)).size();
            for(int i = 0; i < nSpa; i++)
                cout << " ";
            if(to_string(abs(up)).size() < to_string(n).size())
                cout << " ";
            cout << abs(up) << endl;
            if(sum < 0)
                cout << "- ";
            if(bef)
                cout << abs(bef);
            for(int i = 0; i < to_string(n).size(); i++)
                cout << "-";
            cout << endl;
            for(int i = 0; i < nSpa; i++)
                cout << " ";
            cout << n << endl;

        }
    }

    return 0;
}