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

#define inf 1000000000
#define eps 1e-9
int n , indexx;
vvi cells;
vi rows , coloums;
vii answer;
bool check = false;

bool backtarcking(int i) {

    if(i == n) return true;

    for (int j = cells[i][0]; j <= cells[i][2]; ++j) {
        if(rows[j]) continue;
        for (int k = cells[i][1]; k <= cells[i][3]; ++k) {
            if(!coloums[k]) {
                rows[j] = 1;
                coloums[k] = 1;
               // cout<<"i:"<<i<<"    "<< j+1 <<" , "<< k+1<<endl;
                if(backtarcking(i + 1)) {
                    answer[i] = ii(j , k);
                    return true;
                }
                rows[j] = 0;
                coloums[k] =0;
            }
        }
    }
    return false;
}

int main(){
    while (cin >> n && n){
        cells.clear();
        cells.resize(n+1,vi(4));
        answer.clear();
        answer.resize(n , make_pair(0,0));
        rows.clear();
        rows.resize(n , 0);
        coloums.clear();
        coloums.resize(n , 0);
        indexx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                int a; cin >> a;
                cells[i][j] = a - 1;
            }
        }
        if(!backtarcking(0)) cout << "IMPOSSIBLE" << endl;
        else {
            for(auto &e : answer)
                cout << e.first + 1 << " " << e.second + 1 << endl;
        }

    }
}

//int nodes , edges;
//vvi graph;
//vi flag(101 , 0);
//int blacks = 0 , maxblacks = 0;
//
//
//void backtracking(int i) {
//    flag[i] = 1;
//    bool check = false;
//    for (int k, j = 1; j <= nodes; ++j) {
//        for (k = 0; !flag[j] && k < graph[j].size(); ++k) {
//            if (flag[graph[j][k]]) {
//                //check = true;
//                break;
//            }
//        }
//        if (k == graph[j].size() && j) {
//            blacks++;
//            if(maxblacks < blacks)
//                maxblacks = blacks;
//            backtracking(j);
//            flag[j] = 0;
//            blacks--;
//        }
//    }
//
//}
//
//int main() {
//    int tc;
//    cin >> tc;
//    while (tc--) {
//        cin >> nodes >> edges;
//        graph.resize(nodes+1);
//        for (int i = 0; i < edges; ++i) {
//            int first, second;
//            cin >> first >> second;
//            graph[first].push_back(second);
//            graph[second].push_back(first);
//        }
//        backtracking(0);
//        cout << maxblacks<< endl;
//        graph.clear();
//        blacks = 0;
//        maxblacks = 0;
//        flag.clear();
//        flag.resize(101 , 0);
//    }
//}
