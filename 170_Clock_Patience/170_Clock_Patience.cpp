#include <bits/stdc++.h>

using namespace std;

int toNum(char c) {
    if(c == 'A') return 1;
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return c - '0';
}

int main() {
    string str;
    vector<string> cards;
    while(cin >> str && str != "#") {
        cards.push_back(str);
        vector<pair<vector<int>, int >> clo(14);
        vector<vector<string>> tmpHlp(14);
        for(int i = 0; i < 51; i++) {
            cin >> str;
            cards.push_back(str);
        }
        for(int i = 1; i <= 13; i++) {
            for(int j = 0; j < 4; j++) {
                clo[i].first.push_back(toNum(cards[(52 - i) - (j * 13)][0]));
                clo[i].second = 3;
                tmpHlp[i].push_back(cards[(52 - i) - (j * 13)]);
            }
        }
        int s = 0, curr = 13;
        string last;
        while(clo[curr].second >= 0) {
            s++;
            last = tmpHlp[curr][clo[curr].second];
            curr = clo[curr].first[clo[curr].second--];
        }
        printf("%.2d,%s\n", s, last.c_str());
        cards.clear();
    }
    return 0;
}