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

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        vi one(3); // red, Yellow, Blue
        vi two(3); // G, V, O
        int N;
        cin >> N >> one[0] >> two[2] >> one[1] >> two[0] >> one[2] >> two[1];
        bool pos = true;
        for(int i = 0; i < 3; i++)
            if(two[i]) {
                if(one[i] - (two[i] + 1) < 0) {
                    pos = false;
                    break;
                }
                one[i] -= two[i] + 1;
            }
        if(!pos) {
            if(two[0] == one[0] && !two[1] && !two[2] && !one[1] && !one[2]) {
                for(int i = 0; i < two[0]; i++) cout << "GR";
                cout << endl;
            }
            else if(two[1] == one[1] && !two[0] && !two[2] && !one[0] && !one[2]) {
                for(int i = 0; i < two[1]; i++) cout << "YO";
                cout << endl;
            }
            else if(two[2] == one[2] && !two[1] && !two[0] && !one[1] && !one[0]) {
                for(int i = 0; i < two[2]; i++) cout << "BO";
                cout << endl;
            }
            else
                cout << "IMPOSSIBLE" << endl;
        }
        else {
            string ans;
            vector<pair<int, char>> sor(3);
            sor[0] = pair<int, char>(one[0], 'R');
            sor[1] = pair<int, char>(one[1], 'Y');
            sor[2] = pair<int, char>(one[2], 'B');
            sort(sor.begin(), sor.end());
            for(int i = 0; i < 3; i++) {
                while(sor[i].first) {
                    ans += sor[i].second;
                    sor[i].first--;
                    for(int j = 0; j < 3; j++) if(j != i && sor[j].first) {
                        ans += sor[j].second;
                        sor[j].second--;
                        break;
                    }
                }
            }
            if((ans == "R" && !two[1] && !two[2] && !two[3]) || (ans == "Y" && !two[1] && !two[2] && !two[3]) || (ans == "B" && !two[1] && !two[2] && !two[3]))
                cout << ans << endl;
            else if((ans == "R" && !two[1] && !two[2]) || (ans == "Y" && !two[0] && !two[2]) || (ans == "B" && !two[1] && !two[0]))
                cout << "IMPOSSIBLE" << endl;
            else {
                if(ans.size() && ans.back() == ans[0])
                    cout << "IMPOSSIBLE" << endl;
                else {
                    string vio, or, gr;
                    if(two[0]) {
                        gr = "R";
                        for(int i = 0; i < two[0]; i++) gr += "GR";
                    }
                    if(two[1]) {
                        vio = "Y";
                        for(int i = 0; i < two[1]; i++) vio += "VY";
                    }
                    if(two[2]) {
                        or = "B";
                        for(int i = 0; i < two[2]; i++) or += "OB";
                    }
                    if(ans[0] == "R") ans = vio + ans + or + gr;
                    if(ans[1] == "B") ans = vio + ans + gr + or;
                    else ans = or + ans + gr + vio;
                    cout << ans << endl;
                }
            }


        }




    }


    return 0;
}
