//In the name of God
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))

int main() {
    ios::sync_with_stdio(0);
    string QWERTY = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ";
    string DVOARK = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ";
    string M1 = "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    string M2 = "!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";


    string str;
    while(getline(cin, str)){
        for(auto &c: str){
            bool changed = false;
            for (int i = 0; i < DVOARK.size() && !changed; ++i) {
                if(QWERTY[i] == c)
                    c = DVOARK[i], changed = true;
            }
            if(changed) continue;

            for (int i = 0; i < M2.size(); ++i) {
                if(M1[i] == c) {
                    c = M2[i]; break;
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}
