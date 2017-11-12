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
    int n, tc = 0; cin >> n;
    while(n--) {
        tc++;


        int m; cin >> m; // number of clues.
        int number_of_possible_answers = 0;
        vs guesses(m);
        vii correct_missplaced(m);
        for(int i = 0; i < m; i++) { // we get the guesses.
            char tmp;
            cin >> guesses[i];
            cin >> tmp;
            correct_missplaced[i].first = tmp - '0'; // convert char to digit for example '9' to 9
            cin >> tmp >> tmp; // ignore the slash
            correct_missplaced[i].second = tmp - '0';
        }
        string secret;
        for(int i = 0; i <= 9999; i++) { // try all possible values
            string answer;
            for(int j = 0; j < 4 - to_string(i).size(); j++) answer += '0'; // must be 4 digit.
            answer += to_string(i); // we assume this is the secret code.

            bool found_answer = true;
            for(int i = 0; i < m; i++) { // check all guesses
                string tmp_guess = guesses[i], tmp_answer = answer;
                int correct = 0, missplaced = 0;
                for(int i = 0; i < 4; i++)
                    if(tmp_guess[i] == tmp_answer[i])
                        correct++, tmp_guess[i] = tmp_answer[i] = '.'; // we mark the correct gueses.
                for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
                        if(tmp_answer[j] != '.' && tmp_answer[j] == tmp_guess[i]) { // if it is not marked already
                            missplaced++;
                            tmp_answer[j] = tmp_guess[i] = '.'; // we mark this missplaced match so we wont consider it again.
                            break;
                        }
                if(correct != correct_missplaced[i].first || missplaced != correct_missplaced[i].second) { // this guess is no ok
                    found_answer = false;
                    break;
                }

            }
            if(found_answer) {
                number_of_possible_answers++;
                secret = answer;
            }
        }
        if(number_of_possible_answers == 0) cout << "impossible" << endl;
        else if(number_of_possible_answers == 1) cout << secret << endl;
        else cout << "indeterminate" << endl;
    }


    return 0;
}
