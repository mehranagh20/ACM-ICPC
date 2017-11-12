//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n, is_first_test_case = 0;
    while(cin >> n && n) { // if n == 0 then it breaks.
        if(is_first_test_case++) // first time it is 0, so no newline is printed for the first test case.
            cout << endl;

        bool found_at_least_one_solution = false;
        for(int fghij = 1234; fghij <= 98765; fghij++) {
            int abcde = fghij * n;
            if(abcde > 98765) break; // from now on, fghij * n will be 6 digit(or bigger that 98765), so we break.

            vector<int> used(10, 0); // check to see if 0-9 is used in abcde and fghij
            if(abcde < 10000 || fghij < 10000) used[0] = 1; // one of the numbers is 4 digit long.

            int tmp = abcde;
            while(tmp) {
                used[tmp % 10] = 1;
                tmp /= 10;
            }

            tmp = fghij;
            while(tmp) {
                used[tmp % 10] = 1;
                tmp /= 10;
            }

            bool isAnswer = true;
            for(auto &e: used) if(!e) // if all is 1, ok, othewise not ok.
                isAnswer = false;

            if(isAnswer) { // found an answer, we print it.
                found_at_least_one_solution = true;
                cout << setfill('0') << setw(5) << abcde << " / " << setw(5) << fghij << " = " << n << endl;
                // or printf("%.5d / %.5d = %d\n", abcde, fghij);
            }
        }
        if(!found_at_least_one_solution) // no solution is found.
            cout << "There are no solutions for " << n << "." << endl; // not found any solution
    }


    return 0;
}
