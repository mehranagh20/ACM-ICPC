//In The Name Of God
#include <bits/stdc++.h>
#include <pancakes.h>

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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    if(MyNodeId() == 0) {
        int cur = 0, n = GetStackSize() / (NumberOfNodes() - 1);
        for(int i = 1; i <= NumberOfNodes() - 2; i++) {
            PutLL(i, cur);
            PutLL(i, cur + n);
            if(cur == 0) PutLL(i, 0);
            else {
                if(GetStackItem(cur - 1) > GetStackItem(cur)) PutLL(i, 1);
                else PutLL(i, 0);
            }
            cur += n + 1;
        }
        PutLL(NumberOfNodes() - 1, cur);
        PutLL(NumberOfNodes() - 1, GetStackSize() - 1);
        if(GetStackItem(cur - 1) > GetStackItem(cur)) PutLL(i, 1);
        else PutLL(i, 0);
    }
    else {
        ll f = GetLL(), s = GetLL(), amount = GetLL();
        ll pos = f;
        for(; f <= s; f++) {
            ll now = GetStackItem(f);
            if(now < pos) pos = now, amount++;;
            if(now > pos) pos = now;
        }
        if(MyNodeId() != NumberOfNodes() - 1)
            PutLL(NumberOfNodes() - 1, amount);
        else {
            for(int i = 0; i < NumberOfNodes() - 2; i++) {
                ll tmp = GetLL();
                amount += tmp;
            }
            cout << tmp << endl;
        }
    }

    return 0;
}
