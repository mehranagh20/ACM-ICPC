//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
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

vi ans, nums;
int mxP, mxN;

bool solve(int pn, int nn, int curr, int sum) {
    if(nn == mxN && mxP == pn) return sum == 0;
    if(mxP < pn || mxN < nn) return false;
    if(solve(pn + 1, nn, curr + 1, sum + nums[curr])) {
        ans[curr] = nums[curr];
        return true;
    }
    if(solve(pn, nn + 1, curr + 1, sum - nums[curr])) {
        ans[curr] = -nums[curr];
        return true;
    }
    return false;
}

int main() {
    string str;
    while(getline(cin , str) && cin) {
        nums.clear(), ans.clear();
        vi opL = {1}, opR = {1};
        string cur;
        mxP = mxN = 1;
        int i = 0;
        for(; i < str.size(); i++) {
            if(str[i] == ' ') continue;
            if(str[i] == '=') break;
            if(isdigit(str[i])) cur += str[i];
            else {
                str[i] == '-' ? (opL.push_back(-1), mxN++) : (opL.push_back(1), mxP++);
                nums.push_back(stol(cur, NULL));
                cur.clear();
            }
        }
        nums.push_back(stol(cur, NULL)), cur.clear();
        i++;
        for(; i < str.size(); i++) {
            if(str[i] == ' ') continue;
            if(isdigit(str[i])) cur += str[i];
            else {
                str[i] == '-' ? (opR.push_back(-1), mxP++) : (opR.push_back(1), mxN++);
                nums.push_back(stol(cur, NULL));
                cur.clear();
            }
        }
        nums.push_back(stol(cur, NULL));
        ans.resize(nums.size());
        if(solve(0, 0, 0, 0)) {
            bool f = true;
            for(auto &e : opL) {
                for(int j = 0; j < ans.size(); j++) {
                    if(ans[j] == -inf || e * ans[j] < 0) continue;
                    if(f) {
                        cout << ans[j];
                        f = false;
                    }
                    else {
                        if(e > 0) cout << " + " << abs(ans[j]);
                        else cout << " - " << abs(ans[j]);
                    }
                    ans[j] = -inf;
                    break;

                }
            }
            f = true;
            cout << " = ";
            for(auto &e : opR) {
                for(int j = 0; j < ans.size(); j++) {
                    if(ans[j] == -inf || e * ans[j] > 0) continue;
                    if(f) {
                        cout << abs(ans[j]);
                        f = false;
                    }
                    else {
                        if(e > 0) cout << " + " << abs(ans[j]);
                        else cout << " - " << abs(ans[j]);
                    }
                    ans[j] = -inf;
                    break;
                }
            }
            cout << endl;
        }
        else cout << "no solution\n";
    }

    return 0;
}