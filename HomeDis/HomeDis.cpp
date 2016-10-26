#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    int coor[16][2];
    for (int i = 0; i < n * 2; i++) {
        string s;
        cin >> s;
        cin >> tmp;
        coor[i][0] = tmp;
        cin >> tmp;
        coor[i][1] = tmp;
    }
    double dis[16][16];
    for (int i = 0; i < n * 2; i++)
        for (int j = 0; j < n * 2; j++)
            dis[i][j] = (coor[i][0] - coor[j][0]) * (coor[i][0] - coor[j][0]) +
                        (coor[i][1] - coor[j][1]) * (coor[i][1] - coor[j][1]);
    vector<bool> ifAlreadyGrouped(n * 2, false);
    int i , f , leastDis = 1000000, numOfGroups = 0 ;
    double fDis = 0;
    for (numOfGroups; numOfGroups < n; numOfGroups++) {
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 2 * n; k++) {
                if (dis[j][k] < leastDis && (ifAlreadyGrouped[j] || ifAlreadyGrouped[k]) && j != k) {
                    i = j;
                    f = k;
                    leastDis = dis[j][k];
                }
            }
        ifAlreadyGrouped[i] = true;
        ifAlreadyGrouped[f] = true;
        fDis += sqrt(dis[i][f]);
        leastDis = 1000000;
    }
    cout << fixed <<setprecision(3) << fDis;

    return 0;
}