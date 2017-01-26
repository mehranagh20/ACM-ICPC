#include <iostream>
#include <set>
#include <vector>

using namespace std;

int abs (int a ){
    if (a > 0) return a;
    return (-1)*a;
}
#define inf 1000000000
int start; // initialize before function
int n;
vector <vector <int> > dist, memo;
int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
    if (bitmask == (1 << (n + 1)) - 1)
        return dist[pos][start]; // return trip to close the loop
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int ans = inf;
    for (int nxt = 0; nxt <= n; nxt++) // O(n) here
        if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask] = ans;
}

// the answer is in tsp(start, 1 << start); start is the index of starting node

int main (){
    int x , y;
    while(cin >> x >> y){
        vector <pair <int , int> > nuts;
        pair <int , int> src;

        for (int i = 0 ; i < x; i++){
            for (int j = 0 ; j < y ; j++){
                char tmp; cin >> tmp;
                if (tmp == 'L'){
                    src = make_pair(i, j);
                }
                else if (tmp == '#'){
                    nuts.push_back(make_pair(i, j));
                }
            }
        }
        nuts.push_back(src);
        dist = vector <vector <int> > (nuts.size() , vector <int> (nuts.size() , 0));
        for (int i = 0 ; i < nuts.size() ; i++){
            for (int j = 0 ; j < nuts.size() ; j++){
                dist[i][j] = abs(nuts[i].first - nuts[j].first) < abs(nuts[i].second - nuts[j].second) ? abs(nuts[i].first - nuts[j].first) : abs(nuts[i].second - nuts[j].second);
                dist[i][j] += abs(abs(nuts[i].first - nuts[j].first) - abs(nuts[i].second - nuts[j].second));
            }
        }
        memo.resize(nuts.size() + 5, vector<int>((1 << (nuts.size() + 4)), -1));
        vector <vector <int> > &ddd = dist;
        n = nuts.size() - 1;
        start = nuts.size() - 1;
        int mask = (1  << start);
        cout << tsp(start, mask) << endl;
        memo.clear();
        dist.clear();
    }
    return 0;
}
