//In The Name Of God
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, mon; // number of items
vi W, V;
// W array holds weights of items
// V array holds values of items
vvi memo;
// memo array is used to memorize states

// value function returns the most value which holds into w from id to end
int value(int id, int w, int spent) {
    if (id == n ) return 0;
    if (memo[id][w] != -1) return memo[id][w];
    bool flag = false;
    if(spent + W[id] > 2000) flag = true;
    int tmp = w - W[id];
    if ((flag ? tmp : tmp - 200) < 0) return memo[id][w] = value(id + 1, w, spent);
    return memo[id][w] = max(value(id + 1, w, spent), V[id] + value(id + 1, tmp, spent + W[id]));
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> mon >> n) {
        W.resize(n); V.resize(n);
        memo.clear();
        memo.resize(n + 1, vi(mon + 201, -1));
        for (int i = 0; i < n; i++) cin >> W[i] >> V[i];
        for(int i = 0; i < n; i++) for(int j = 0; j < n - 1; j++)
                if(W[j] > W[j + 1]) {
                    swap(W[j], W[j + 1]);
                    swap(V[j], V[j + 1]);
                }
        cout << value(0, mon + 200, 0) << endl;
    }

    return 0;
}