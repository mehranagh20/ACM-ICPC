#include <iostream>
#include <string>

using namespace std;

int main() {
    int height, disProg, day = 0;
    double prog, factor, goneHei = 0;
    while (cin >> height >> prog >> disProg >> factor && height != 0) {
        factor = ((factor / 100)) * prog;
        while (true) {
            day++;
            if (prog > 0)
                goneHei += prog;
            if (goneHei > (double) height) {
                cout << "success on day " << day << endl;
                break;
            }
            goneHei -= disProg;
            if (goneHei < 0) {
                cout << "failure on day " << day << endl;
                break;
            }
            prog -= factor;
        }
        goneHei = 0;
        day = 0;
    }

    return 0;
}