#define Q416
#ifdef Q416

#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

map <string ,int > m1;  map < int , string > m2;
int n;
vs vec;  string arr;


int led ( int indx , int num){
    if ( indx == 0 && num < n - 1) return -1;
    if ( indx == n) return 1;
    string base = m2[num];
    for ( int i = 0; i < vec[indx].size(); i++){
        if ( arr[i] == '0' && base[i] == '1') return 0;
        if ( arr[i] == '0' && base[i] == '1' && vec[indx][i] == '0') arr[i] = '0';
    }
    for ( int i = 0; i < vec[indx].size(); i++)
        if ( base[i] == '0' && vec[indx][i] == '1') return 0;
    for ( int i = 0 ; i < n; i++)
        return led ( indx + 1 , num - 1);
}

/*bool check ( string a, string b){
    for ( int i = 0; i < a.size(); i++)
        if ( a[i] == '1' && b[i] == '0') return false;
    return true;
}

int give ( int num ){
    for ( int i = num; i >= n-1; i--)
        if ( check( m2[i] , vec[0]))  return i;
}*/

int main(){

    ios::sync_with_stdio(0);

    m1["YYYYYYN"] = 0; m2[0] = "YYYYYYN";
    m1["NYYNNNN"] = 1; m2[1] = "NYYNNNN";
    m1["YYNYYNY"] = 2; m2[2] = "YYNYYNY";
    m1["YYYYNNY"] = 3; m2[3] = "YYYYNNY";
    m1["NYYNNYY"] = 4; m2[4] = "NYYNNYY";
    m1["YNYYNYY"] = 5; m2[5] = "YNYYNYY";
    m1["YNYYYYY"] = 6; m2[6] = "YNYYYYY";
    m1["YYYNNNN"] = 7; m2[7] = "YYYNNNN";
    m1["YYYYYYY"] = 8; m2[8] = "YYYYYYY";
    m1["YYYYNYY"] = 9; m2[9] = "YYYYNYY";
    while ( cin >> n && n ){
        vec.clear();  vec.resize(n);
        arr.clear(); arr.resize(8 , '1');
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        bool ok = false;
        for ( int i = 9; i >= 0; i--){
            int ans = led ( 0 , i);
            if ( ans == 1 ){
                ok = true;
                break;
            }
            if ( ans == 0) {
                arr.clear();
                arr.resize( 8 , '1');
                continue;
            }
            if ( ans == -1) break;
        }
        if ( ok ) cout <<"MATCH\n";
        else cout << "MISMATCH\n";
    }
return 0;
}

#endif
