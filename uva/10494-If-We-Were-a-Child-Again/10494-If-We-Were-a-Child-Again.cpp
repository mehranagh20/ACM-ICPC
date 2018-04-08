//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    char c;
    string s, dev;
    long long rem, sec;
    while(cin >> s >> c >> sec) {
        dev = "";
        rem = 0; int start = 0;
        for(int i = 0; i < s.size(); i++) {
            rem = s[i] - '0' + 10 * rem;
            if(rem / sec) start = 1;
            if(start) dev += (rem / sec) + '0';
            rem = rem % sec;
        }
        if(!start) dev = "0";
        if(c == '%') cout << rem << endl;
        else cout << dev << endl;
   }
    return 0;
}