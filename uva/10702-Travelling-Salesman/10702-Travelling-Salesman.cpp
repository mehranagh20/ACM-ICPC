//                                                  In The Name Of God
//                                              programmer:Mohammad Dehghan
#include <iostream>
using namespace std;

#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <sstream>
#include <bitset>

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
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back



vvi memo , graph;
int cities , start , endss , interc;
set<int> endc;

int dp(int m , int id) {
    if (m == interc && endc.count(id)) {
        return 0;
    }
    if(m >= interc )
        return -9999999;
    int &nec = memo[m][id];
    if( nec != -1)
        return nec;
    nec = 0;
    for (int i = 0; i < cities; ++i) {
        if (i != id)
            nec = max(nec, graph[id][i] + dp(m+1 , i));
    }
    return nec;
}

int main(){
    while(cin >> cities >> start >> endss >> interc && cities){
        graph.assign(cities , vi ( cities , 0));
        for (int i = 0; i < cities; ++i) {
            for (int j = 0; j < cities; ++j) {
                cin >> graph[i][j];
            }
        }
        endc.clear();
        for (int k = 0; k < endss; ++k) {
            int temp;
            cin >> temp;
            endc.insert(temp - 1);
        }
        memo.assign(interc+1 , vi(cities+1 , -1));
        cout << dp(0 , start - 1)<<endl;
    }
}

//vector<pair<char , long long int>> stones;
//
//long long int between(long long int left , long long int right){
//    long long int a = left+1 , b= left+2 , max = 0 , lasta = left , lastb = left;
//    if(right - left == 1){
//        return (stones[right].second - stones[left].second);
//    }
//    for (; b <= right;) {
//        if (stones[a].second - stones[lasta].second > max)
//            max = stones[a].second - stones[lasta].second;
//        if (stones[b].second - stones[lastb].second > max)
//            max = stones[b].second - stones[lastb].second;
//        lasta = a;
//        lastb = b;
//        a += 2;
//        b += 2;
//    }
//    a -= 2;
//    if(stones[right].second - stones[a].second > max)
//        max = stones[right].second - stones[a].second;
//    return max;
//}
//
//
//int main(){
//    int tc;
//    cin >> tc;
//    for(int kk = 1; kk <= tc ; kk++){
//        long long int stone , distance;
//        cin >> stone >> distance;
//        stones.clear();
//        stones.resize(stone+2);
//        stones[0].second = 0;
//        stones[stone+1].second = inf;
//        vector<long long int> Bstones;
//        for (int i = 1; i <=stone; ++i) {
//            string s , temp;
//            cin >> s;
//            stones[i].F = s[0];
//            for (int j = 2; j <s.size() ; ++j) {
//                temp[j-2] = s[j];
//            }
//            stones[i].S = stoi(temp);
//            if(s[0] == 'B')
//                Bstones.push_back(i);
//        }
//        std::sort(stones.begin(), stones.end(), [](const std::pair<char,long long int> &left, const std::pair<char,long long int> &right) {
//            return left.second < right.second;
//        });
//        stones[0].second = 0;
//        stones[stone+1].second = distance;
//        long long int max  = 0;
//        if(Bstones.size()) {
//            if (between(0, Bstones[0]) > max)
//                max = between(0, Bstones[0]);
//            for (int j = 1; j < Bstones.size(); ++j) {
//                if (between(Bstones[j - 1], Bstones[j]) > max)
//                    max = between(Bstones[j - 1], Bstones[j]);
//            }
//            if (between(Bstones[Bstones.size() - 1], stone + 1) > max)
//                max = between(Bstones[Bstones.size() - 1], stone + 1);
//        } else{
//            max = between(0 , stone +1);
//        }
//        cout <<"Case "<<kk<<": "<< max <<endl;
//    }
//}
