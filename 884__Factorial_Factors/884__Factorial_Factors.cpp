#include <iostream>
#include <vector>

using namespace std;

int main (){
    vector <long long> terms(1000001 , 0);
    vector <bool> calced (1000001 , false);

    for (int i = 2 ; i < 1000001 ; i++){
        if (calced[i]) continue;
        calced[i] = true;
        terms[i] ++;
        for (int j = 2 * i ; j < 1000001 ; j += i) {
            terms[j] = terms[i] + terms[j/i];
            calced[j] = true;
        }
    }

    for (int i = 1 ; i < 1000001 ; i++){
        terms[i] += terms[i - 1];
    }
    int input;
    while (cin >> input){
        cout << terms[input] << endl;
    }

    return 0;
}
