#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(long long int a) {
    string str = to_string(a);
    for(int i = 0; i < str.size() / 2; i++)
        if(str[i] != str[str.size() - 1 - i])
            return false;
    return true;

}

long long int reve(long long int a) {
    long long int re = 0;
    while(a) {
        re = re * 10 + a % 10;
        a /= 10;
    }
    return re;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        long long int n;
        cin >> n;
        int i = 1;
        n += reve(n);
        while(!isPalindrome(n)) {
            n += reve(n);
            i++;
        }
        cout << i << " " << n << endl;
    }
}

