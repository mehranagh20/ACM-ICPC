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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

vi pal;
vector<long long> seq, nums;
void solve(int i, int j, int ind) {
    if(j > i) return;
    if(i == j) {
        pal[i] = ind - 1;
        return;
    }
    pal[i] = pal[j] = 0;
    if(i == j + 1) {
        pal[i] = pal[j] = ind - 1;
        return;
    }
    else {
        ll num_pal = nums[i - j - 2];
        while(ind > num_pal) {
            pal[i] = pal[j] = pal[i] + 1;
            ind -= num_pal;
        }
        solve(i - 1, j + 1, ind);
    }
}

int main() {
    ios::sync_with_stdio(0);
    seq = {10, 10};
    vector<long long> seq2 = {9, 9};
    while(seq.back() < 1e9 * 2) {
        ll b = seq.back();
        seq.push_back(b * 10), seq.push_back(b * 10);
    }
    while(seq2.back() < 1e9 * 2) {
        ll b = seq2.back();
        seq2.push_back(b * 10), seq2.push_back(b * 10);
    }
    nums = seq;
    seq = seq2;
    for(int i = 1; i < seq2.size(); i++) seq2[i] += seq2[i - 1];

    ll ind;
    while(cin >> ind && ind) {
        int n;
        for(int i = 0; i < seq2.size(); i++) if(seq2[i] >= ind){
            n = i + 1;
            break;
        }
        ind -= n - 2 < 0 ? 0 : seq2[n - 2];
        int i = n - 1, j = 0;
        pal.assign(n, 0);
        if(i == j) {
            pal[i] = ind;
        }
        else {
            pal[i] = pal[j] = 1;
            if(i == j + 1) {
                pal[i] = pal[j] = ind;
            }
            else {
                ll num_pal = nums[i - j - 2];
                while(ind > num_pal) {
                    pal[i] = pal[j] = pal[i] + 1;
                    ind -= num_pal;
                }
                nums[0] = nums[1] = 10;
                solve(i - 1, j + 1, ind);
            }
        }
        for(int i = 0; i < n; i++) cout << pal[i];
        cout << endl;
    }



    return 0;
}
