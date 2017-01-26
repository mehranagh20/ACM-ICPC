#include <iostream>
#include <iomanip>

using namespace std;

int main (){
    int test; cin >> test;
    double pi = 3.14159265359;
    int cs = 0;
    while (test--){
        cs++;
        double r; double v; cin >> r >> v;
        cout << "Case " << cs << ": ";
        cout << fixed << setprecision(7) << (r * pi)/ (v * 2.0) << endl;
    }

    return 0;
}
