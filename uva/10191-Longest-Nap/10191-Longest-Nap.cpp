//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, num, TC = 1;
    string f, s, str;
    while(cin >> n) {
        int max = -1; string start;
        vector<pair<int, string>> st, fi;
        st.push_back(make_pair(10 * 60, "10:00")); fi.push_back(make_pair(18 * 60, "18:00"));
        for(int i = 0; i < n; i++) {
            cin >> s >> f; getline(cin, str);
            num = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0'; fi.push_back(make_pair(num, s));
            num = ((f[0] - '0') * 10 + f[1] - '0') * 60 + (f[3] - '0') * 10 + f[4] - '0'; st.push_back(make_pair(num, f));
        }
        sort(fi.begin(), fi.end());
        sort(st.begin(), st.end());
        for(int i = 0; i < st.size(); i++) {
            if(fi[i].first - st[i].first > max) {
                max = fi[i].first - st[i].first;
                start = st[i].second;
            }
        }
        printf("Day #%d: ", TC++);
        if(max < 60) printf("the longest nap starts at %s and will last for %d minutes.\n", start.c_str(), max);
        else printf("the longest nap starts at %s and will last for %d hours and %d minutes.\n", start.c_str(), max / 60, max % 60);
    }
    return 0;
}
