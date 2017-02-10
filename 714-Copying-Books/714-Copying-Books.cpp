//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

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

vi books;
int m, k;
bool pos(ll mx) {
    int num = 1, sum = 0;
    for(int i = 0; i < m; i++) {
        if(sum + books[i] <= mx) sum += books[i];
        else {
            num++;
            if(books[i] > mx) num = inf;
            sum = books[i];
        }
    }
    return num <= k;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> m >> k;
        ll sum = 0;
        books.assign(m, 0);
        for(int i = 0; i < m; i++) cin >> books[i], sum += books[i];
        ll low = 0, high = sum, ans = -inf;
        while(low <= high) {
            ll mid = (low + high) / 2;
            if(pos(mid)) high = mid - 1, ans = mid;
            else low = mid + 1;
        }
        sum = 0;
        vvi answers(k);
        int ind = 0;
        for(int i = m - 1; i >= 0; i--) {
            if((sum + books[i] <= ans) && (i) >= (k - ind - 1)) {
                answers[ind].push_back(books[i]);
                sum += books[i];
            }
            else {
                ind++;
                answers[ind].push_back(books[i]);
                sum = books[i];
            }
        }
        for(int j = k - 1; j >= 0; j--) {
            for(int i = answers[j].size() - 1; i >= 0; i--) {
                if(i < answers[j].size() - 1) cout << " ";
                cout << answers[j][i];
            }
            if(j)
                cout << " / ";
        }
        cout << endl;

    }

    return 0;
}
