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
typedef pair<long double, long double> ii;
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

//
//int main() {
//
//
//    char *c = (char *) malloc(300);
//    char *c2 = (char *) malloc(300);
//    *c2 = 'a';
//    for(; *c2 != '\n' ;) {
//        fgets(c2, 200, stdin);
//        strcat(c , c2);
//    }
//    //printf("%s" , c);
//    char * find = (char*) malloc(300);
//    char * entrance = (char*) malloc(300) ;
//    fgets( entrance , 200 , stdin) ;
//    entrance = strtok(entrance , "\n");
//   // printf("%s" , entrance);
//
//    find = c;
//    for(; (find) != NULL ; c++){
//        c = find;
//        find = strstr(c , entrance);
//        for (int i = 0;find!= NULL && find[i] != '\n' ; ++i) {
//            printf("%c" , find[i]);
//        }
//        puts("");
//        int j;
//        for ( j = 0;find!=NULL && (find[j] == entrance[j]); ++j) {
//
//        }
//        find += j;
//        //strtok(c , entrance);
//
//
//    }
//    puts("");
//
//}
//int nodes , edges;
//vvi graph(nodes);
//
//void backtracking(int i){
//
//}
//
//int main(){
//    int tc;
//    cin >> tc;
//    while (tc--){
//        cin>> nodes >> edges;
//        for (int i = 0; i < edges; ++i) {
//            int first , second;
//            cin >> first >> second;
//            graph[first].push_back(second);
//        }
//        backtracking(0);
//
//    }
//}

//
//int main(){
//    int num , tc = 0;
//    while (cin>> num){
//        tc++;
//        long long max = 0;
//        vector<long long> numbers(num);
//        for (int i = 0; i < num; ++i) {
//            cin>> numbers[i];
//        }
//        long long sum = 0;
//        for (int j = 0; j < num; ++j) {
//            sum = numbers[j];
//            if(max < sum)
//                max = sum;
//            for (int i = j+1; i <num ; ++i) {
//                sum = sum * numbers[i];
//                if(max < sum)
//                    max = sum;
//            }
//            sum = 0;
//        }
//        cout <<"Case #"<<tc<<": The maximum product is "<< max <<"."<<endl<<endl;
//    }
//}

int main() {
    ios::sync_with_stdio(0);
    int tc;
    cin >> tc;

    long long C, R;
    for (int k = 0; k < tc; ++k) {
        vector<long long> numbers;
        cin >> C >> R;
        if (C == R) {
            cout <<"Case #"<< k+1 <<": "<<0<<endl;
            continue;
        }
        C -= R;
        long double sq = sqrt((double) C);
        for (long long i = 1; i <= sq; ++i) {
            if (!(C % i)) {
                if (i > R)
                    numbers.push_back(i);
                if ((C / i) > R && ((C/i)!= i))
                    numbers.push_back(C / i);
            }
        }
        sort(numbers.begin(), numbers.end());
        cout <<"Case #"<< k+1 <<":";
        for (int j = 0; j < numbers.size(); ++j) {
            cout<<" "<<numbers[j];
        }
        cout << endl;
    }
}
//int n , m;
//viii domines;
//vii finallist;
//ii first , last;
//bool finished = false;
//
//void backtrack (int index) {
//    if (index == n + 1) {
//        finished = true;
//        return;
//    }
//    for (int i = 0; i < 2*m && !finished; ++i) {
//        if (!domines[i].first && (domines[i].second.first == finallist[index - 1].second)) {
//            if (index == n && (domines[i].second.second != last.first))
//                continue;
//            finallist[index] = domines[i].second;
//            domines[i].first = 1;
//            if (!(i % 2))
//                domines[i + 1].first = 1;
//            else
//                domines[i - 1].first = 1;
//            backtrack(index + 1);
//            domines[i].first = 0;
// //           domines[i].second = make_pair(inf , inf);
//            if (!(i % 2)) {
//                domines[i + 1].first = 0;
// //               domines[i + 1].second = make_pair(inf, inf);
//            }
//            else {
//                domines[i - 1].first = 0;
//  //              domines[i - 1].second = make_pair(inf, inf);
//            }
//        }
//    }
//
//}
//
//int main(){
//
//    while (cin >> n >> m && n){
//        domines.clear();
//        domines.resize(2*m,make_pair(0 , make_pair(0,0)));
//        finallist.clear();
//        finallist.resize(n+1);
////        finallist[n-1].first = last.first;
////        finallist[n-1].second = last.second;
//        cin>>first.first>>first.second>>last.first>>last.second;
//        finallist[0].first = first.first;
//        finallist[0].second = first.second;
//        for (int i = 0; i < 2*m; ++i) {
//            cin>>domines[i].second.first>>domines[i].second.second;
//            domines[i+1].second.first = domines[i].second.second;
//            domines[i+1].second.second = domines[i].second.first;
//            ++i;
//        }
//        backtrack(1);
//        if(finished)
//            cout <<"YES"<<endl;
//        else
//            cout << "NO"<<endl;
//        finished = false;
//    }
//}

//
//int main(){
//
//    int tc ;
//    cin >> tc;
//    while (tc--){
//        int n ;
//        cin >> n;
//        int min =2 ;
//        int i , n2 = (n-4)/2;
//        for ( i = 1; i <=2*n2; ++i) {
//            min+=i*2;
//        }
//        if((n-4) % 2 == 1)
//            min+= i;
//        cout << min<<endl;
//    }
//
//}
