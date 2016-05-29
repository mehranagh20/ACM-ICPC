#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> p(26);

void UFDS()
{
    for(char c = 'A'; c <= 'Z'; c++)
        p[c - 65] = c - 65;
}

int findSet(int c)
{
    return (p[c] == c ? c : findSet(p[c]));
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void merge(int i, int j, int &num)
{
    if(!isSameSet(i, j))
    {
        num++;
        int a = findSet(i), b = findSet(j);
        if(a < b)
            p[b] = a;
        else
            p[a] = b;
    }
}

int main() {
    int n;
    cin >> n;
    while (getchar() != '\n');
    while (n--) {
        bitset<26> hlp(0);
        UFDS();
        int num = 1;
        string s;
        while (getline(cin, s) && s[0] != '*') {
            hlp[s[1] - 65] = 1;
            hlp[s[3] - 65] = 1;
            merge(s[1] - 65, s[3] - 65, num);
        }
        getline(cin, s);
        int ava = s.size() / 2 + 1;
        int co = s.size() / 2 + 1 - hlp.count();
        printf("There are %d tree(s) and %d acorn(s).\n", ava - num - (co - 1), co);
    }
    return 0;
}