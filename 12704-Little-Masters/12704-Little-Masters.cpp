//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
     int tc;
    cin >> tc;
    while(tc--) {
        double x, y, r;
        cin >> x >> y >> r;
        if(x == 0) {printf("%.2lf %.2lf\n", r, r);
        }
        else {
            double m = y / x;
            double xx = sqrt(r * r / (1 + m * m));
            double yy = m * xx;
            double Mdis = sqrt((pow(x - xx, 2) + pow(y - yy, 2)));
            double minDis = abs(r * 2 - Mdis);
            if (minDis > Mdis) {
                double tmp = minDis;
                minDis = Mdis;
                Mdis = tmp;
            }
            printf("%.2lf %.2lf\n", minDis, Mdis);
        }

    }


    return 0;
}
