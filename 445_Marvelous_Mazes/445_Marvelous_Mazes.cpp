//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int num = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') puts("");
        else {
            if (c == '!') {
                puts("");
                continue;
            }
            if (isdigit(c)) num += c - '0';
            else {
                if (c == 'b') {
                    for (int i = 0; i < num; i++)
                        putchar(' ');
                }
                else
                    for (int i = 0; i < num; i++)
                        putchar(c);
                num = 0;
            }
        }

    }

    return 0;
}