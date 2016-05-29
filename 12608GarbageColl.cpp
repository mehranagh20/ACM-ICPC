#include <iostream>

using namespace std;

int main() {
    int nCases;
    cin >> nCases;
    while (nCases--) {
        int nPoint, maxWei, disGone = 0, currWei = 0, currDis = 0;
        cin >> maxWei >> nPoint;
        for (int i = 0; i < nPoint; i++) {
            int pDis, pWei;
            cin >> pDis >> pWei;
            disGone += pDis - currDis;
            currDis = pDis;
            if (pWei + currWei > maxWei) {
                disGone += (currDis * 2);
                currWei = pWei;
            }
            else
                currWei += pWei;
            if (currWei == maxWei && i != nPoint - 1) {
                currWei = 0;
                disGone += (currDis * 2);
            }
        }
        cout << disGone + currDis << endl;
    }

    return 0;
}