//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef vector<long long> vi;
typedef vector<vi> vvi;

int n; // number of coin types
vi coinValue; // holds the value of coins
vvi memo; // used to memorize the states

unsigned long long ways(int type, int value) {
    if (value == 0)              return 1;
    if (value < 0 || type == n)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main() {
    ios::sync_with_stdio(0);
    coinValue = {1, 5, 10, 25, 50}; n = 5;
    int num; memo.resize(5, vi(30001, -1));
    while(cin >> num) {
        unsigned long long w = ways(0, num);
        if(w == 1) printf("There is only 1 way to produce %d cents change.\n", num);
        else printf("There are %llu ways to produce %d cents change.\n", w, num);
    }

    return 0;
}