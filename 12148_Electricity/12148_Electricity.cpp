#include <bits/stdc++.h>

using namespace std;

int monthDay(int year, int m) {
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 12 || m == 10) return 31;
    else if(m == 4 || m == 6 || m == 11 || m == 9) return 30;
    if((!(year % 4) && !(year % 100) && !(year % 400)) || !(year % 4) && (year % 100))
        return 29;
    return 28;
}

int main() {
    int n;
    while(cin >> n && n) {
        long long d, m, y, c, sum = 0, pD, pM, pY, pC, total = 0;
        cin >> pD >> pM >> pY >> pC;
        for (int i = 0; i < n - 1; i++) {
            cin >> d >> m >> y >> c;
            if (pY == y) {
                if (pM == m) {
                    if(pD + 1 == d) {
                        sum += c - pC;
                        total++;
                    }
                }
                else if ((pM + 1 == m || (pM == 12 && m == 1)) && d == 1) {
                    if (monthDay(pY, pM) == pD) {
                        sum += c - pC;
                        total++;
                    }
                }
            }
            else if (pY + 1 == y && pM == 12 && pD == monthDay(pY, pM)) {
                if (m == 1 && d == 1) {
                    total++;
                    sum += c - pC;
                }
            }
            pD = d;
            pY = y;
            pM = m;
            pC = c;
        }
        cout << total << " " << sum << endl;
    }
    return 0;
}