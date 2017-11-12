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
    int k, tmp; cin >> k; // number of test cases.
    while(k--) {
        int n, m; cin >> n >> m;
        set<int> u; // set u
        vector<set<int>> sets(m); // list of all sets, s1, s2, ..., sm
        cin.ignore(); // ignores the \n after m
        for(int i = 0; i < m; i++) {
            string line;
            getline(cin, line); // get entire line, becase we do not know how many numbers we should get.
            stringstream stream(line); // convert line to stream so it can be readen like cin.
            while(stream >> tmp) // reading from line.
                sets[i].insert(tmp), u.insert(tmp);
        }

        vi u_items; // we copy u's items to a vector for convenience
        for(auto it = u.begin(); it != u.end(); it++) u_items.push_back(*it);

        bool has_answer = false; // true if we find an answer.

        // try all possible colorings with bitmask, 0 is blue, 1 is red.
        int coloring = 0; // all of the bits are 0, so all of the items are blue at first.
        while(coloring < (1 << n)) { // try all possible colorings by changing bits of the int. we only need n bits of the int.
            has_answer = true; // false if we find a set which does not have different colors.
            for(int i = 0; i < m; i++) { // check all sets to see if has different colors (red and blue)
                bool has_blue = false, has_red = false;
                for(int j = 0; j < n; j++) {
                    if((coloring & (1 << j)) && sets[i].find(u_items[j]) != sets[i].end()) // if current item is red and it is in ith set
                        has_red = true;
                    if(!(coloring & (1 << j)) && sets[i].find(u_items[j]) != sets[i].end()) // if current item is blue and it is in ith set
                        has_blue = true;
                }
                if(!has_red || !has_blue) { // if colors in ith set was not different, there is no point to continue this set of coloring. {
                    has_answer = false;
                    break;
                }
            }
            if(has_answer) // we have found an answer so we should print
                break;

            coloring++; // get another coloring.
        }
        cout << (has_answer ? "Y" : "N");
    }


    return 0;
}
