#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;


int main() {
    long long s, d;
    while(scanf("%lld %lld", &s, &d) == 2) {
        long long i = s, sum = 0;
        while(1) {
            sum += i;
            if(sum >= d) {
                printf("%lld\n", i);
                break;
            }
            i++;
        }
    }
    return 0;
}