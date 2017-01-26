#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main (){
    int n;
    int testno = 0;
    while (cin >> n){
        if (n == 0) return 0;
        // if (testno != 0) cout << endl;
        // testno ++;
        vector <vector <double> > matrix(n ,vector <double> (n , 0));
        vector <vector <double> > inverse(n ,vector <double> (n , 0));
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                double k; cin >> k;
                matrix[i][j] = k;

                if (i == j){
                    inverse[i][j] = (1);
                } else inverse[i][j] = (0);
            }
        }
        bool impos = false;
        for (int i = 0 ; i < n ; i++){
            double pivet = matrix[i][i];
            if (pivet == 0){

                // for (int j = i + 1 ; j < n ; j++){
                //     if (matrix [j][i] != 0){
                //         swap (matrix[j] , matrix[i]);
                //         swap (inverse[j] , inverse[i]);
                //
                //         break;
                //     }
                // }
                // pivet = matrix[i][i];
                // if (pivet == 0){
                //     impos = true;
                //     break;
                // }
                impos = true;

            }
            if (impos) break;
            for (int k = 0 ; k < n ; k++){
                matrix[i][k] /= pivet;
                inverse[i][k] /= pivet;
            }
            for (int j = 0 ; j < n ; j++){
                if (j == i) continue;
                double coef = matrix[j][i];
                for (int k = 0 ; k < n ; k++){
                    matrix[j][k] -= matrix[i][k] * coef;
                    inverse[j][k] -= inverse[i][k] * coef;
                }
            }
        }
        if (impos) cout << "Not possible" << endl;
        else
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){

                cout <<  fixed << setprecision(6) <<inverse[i][j];
                if (j != n - 1) cout << " ";
             }
             cout << endl;
        }
        cout << endl;
    }

    return 0;
}
