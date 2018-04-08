#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    for(int i = 1; i <= n; i++) {
        printf("Case %d: ", i);
        vector<string> cards;
        cards.reserve(52);
        string tmp;
        while(cards.size() < 52) {
            cin >> tmp;
        }
        while(cards.size() < 52) {
            cin >> tmp;
            if(tmp != "\n")
                cards.push_back(tmp);
        }
        int indesx = 26, y = 0;
        for(int j = 0; j < 3; j++) {
            int x;
            if(isdigit(cards[indesx][0]))
                x = cards[indesx][0] - '0';
            else
                x = 10;
            y += x;

            x = 10 - x;
            indesx -= x + 1;
        }
        if(y <= indesx)
            cout << cards[y] << endl;
        else {
            int x = y + (26 - indesx) - 1;
            cout << cards[x] << endl;
        }

    }
    return 0;
}