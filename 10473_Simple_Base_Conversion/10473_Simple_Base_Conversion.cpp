//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8

int main() {
    ll num;
    string str;
    while(getline(cin, str)) {
        if(str.size() > 2 && str.find("0x") != str.npos) {
            stringstream ss(str);
            ss >> hex >> num;
            cout << dec << num << endl;
        }
        else {
            num = atoll(str.c_str());
            if(num < 0) break;
            cout << "0x" << uppercase << hex << num << endl;
        }
    }
    return 0;
}