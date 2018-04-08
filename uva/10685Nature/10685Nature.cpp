#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

string findSet(string i, map<string, string> &set) {
    return (set[i] == i ? i : findSet(set[i], set));
}

void merge(string i, string j, map<string, string> &set, map<string, int> &num, int &max) {
    string setI = findSet(i, set), setJ = findSet(j, set);
    if (setI != setJ) {
        if (setI < setJ) {
            set[setJ] = setI;
            num[setI] += num[setJ];
            if (num[setI] > max)
                max = num[setI];
        }
        else {
            set[setI] = set[setJ];
            num[setJ] += num[setI];
            if (num[setJ] > max)
                max = num[setJ];
        }
    }
}

int main() {
    int nS, nG;
    while (cin >> nS >> nG && (nS || nG)) {
        map<string, string> set;
        map<string, int> num;
        int max = 1;
        while(getchar() != '\n');
        while (nS--) {
            string s;
            getline(cin, s);
            set.insert(make_pair(s, s));
            num.insert(make_pair(s, 1));
        }
        while(nG--){
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            merge(tmp1, tmp2, set, num, max);
            while(getchar() != '\n');
        }
        printf("%d\n", max);
    }
    return 0;
}