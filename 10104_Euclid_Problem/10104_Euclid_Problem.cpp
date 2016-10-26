//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8
int x, y;

int gcd(int a, int b, int &s0, int &s1, int &t0, int &t1) {
    if(b == 0) {
        t1 = 0; s1 = 1;
        return a;
    }
    if(a % b == 0) return b;
    int tmp = s1;
    s1 = s0 - (a / b) * s1;
    s0 = tmp;
    tmp = t1;
    t1 = t0 - (a / b) * t1;
    t0 = tmp;
    return gcd(b, a % b, s0, s1, t0, t1);
}

int main() {
    ios::sync_with_stdio(0);
    ll num1, num2;
    while(cin >> num1 >> num2) {
        if(num1 == num2) {
            cout << 0 << " " << 1 << " " << num1 << endl;
        }
        else {
            int s0 = 1, s1 = 0, t0 = 0, t1 = 1;
            if (num2 < num1) {
                int cd = gcd(num1, num2, s0, s1, t0, t1);
                cout << s1 << " " << t1 << " " << cd << endl;
            }
            else {
                int cd = gcd(num2, num1, s0, s1, t0, t1);
                cout << t1 << " " << s1 << " " << cd << endl;
            }
        }
    }

    return 0;
}