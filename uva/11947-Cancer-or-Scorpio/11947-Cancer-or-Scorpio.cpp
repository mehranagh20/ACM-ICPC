//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
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
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9
#define EXPLORED 2
#define UNVISITED 0
#define VISITED 1

bool isLeap(int y) {
    if(y % 4 == 0) {
        if(y % 100 != 0) return true;
    }
    if(y % 400 == 0) return true;
    return false;
}

int main() {
    //cout << isLeap(2001) << endl;
    int tc; cin >> tc;
    vi months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<pair<ii, ii>> signs = {pair<ii, ii>(ii(1, 21), ii(2, 19)), pair<ii, ii>(ii(2, 20), ii(3, 20)),pair<ii, ii>(ii(3, 21), ii(4, 20)),pair<ii, ii>(ii(4, 21), ii(5, 21)),
                                  pair<ii, ii>(ii(5, 22), ii(6, 21)),pair<ii, ii>(ii(6, 22), ii(7, 22)),pair<ii, ii>(ii(7, 23), ii(8, 21)),pair<ii, ii>(ii(8, 22), ii(9, 23)),
                                  pair<ii, ii>(ii(9, 24), ii(10, 23)),pair<ii, ii>(ii(10, 24), ii(11, 22)),pair<ii, ii>(ii(11, 23), ii(12, 22)),pair<ii, ii>(ii(12, 23), ii(1, 20))};
    vector<string> nSigns = {"aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
    for(int i = 0; i < tc; i++) {
        months[1] = 28;
        string str; cin >> str;
        int m = (str[0] - '0') * 10 + (str[1] - '0'), d = (str[2] - '0') * 10 + (str[3] - '0'), y = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');
        if(isLeap(y))
            months[1] = 29;
        for(int i = 0; i < 40 * 7; i++) {
            if(d + 1 > months[m - 1]) {
                d = 1;
                if(m + 1 > 12) {
                    m = 1; y++;
                    if(isLeap(y)) months[1] = 29;
                    else months[1] = 28;
                }
                else m++;
            }
            else d++;
        }
        string si;
        for(int i = 0; i < months.size(); i++) {
            if((m == signs[i].first.first && d >= signs[i].first.second) || (m == signs[i].second.first && d <= signs[i].second.second)) {
                si = nSigns[i];
                break;
            }
        }
        si[0] = tolower(si[0]);
        cout << i + 1 << " " << setw(2) << setfill('0') << m << "/" << setw(2) << setfill('0') << d << "/" << setw(4) << setfill('0') << y << " " << si << endl;
    }
}
