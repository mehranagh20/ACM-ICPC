#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void buildTree(int p, int l, int r, vector<unsigned int> &segTree, string &pirates, vector<pair<int, int>> &hllp) {
    hllp[p].first = l;
    hllp[p].second = r;
    if (l == r)
    {
        if(pirates[l] == '1')
            segTree[p] = 1;
        else
            segTree[p] = 0;
    }
    else {
        buildTree(p << 1, l, (l + r) / 2, segTree, pirates, hllp);
        buildTree((p << 1) + 1, (l + r) / 2 + 1, r, segTree, pirates, hllp);
        segTree[p] = segTree[p << 1] + segTree[(p << 1) + 1];
    }
}

void appropLa(int p, char c, vector<char> &lazy) {
    if (lazy[p]) {
        if (c == 'I') {
            if (lazy[p] == 'I')
                lazy[p] = 0;
            else if (lazy[p] == 'E')
                lazy[p] = 'F';
            else
                lazy[p] = 'E';
        }
        else
            lazy[p] = c;
    }
    else
        lazy[p] = c;
}


void up(int p, int l, int r, vector<char> &lazy, vector<unsigned int> &segTree) {
    if (lazy[p] == 'I')
        segTree[p] = (r - l + 1) - segTree[p];
    else if (lazy[p] == 'E')
        segTree[p] = 0;
    else
        segTree[p] = r - l + 1;
    if(l != r) {
        appropLa(p << 1, lazy[p], lazy);
        appropLa((p << 1) + 1, lazy[p], lazy);
    }
    lazy[p] = 0;
}

void updateTree(int p, int i, int j, int l, int r, char c, vector<char> &lazy, vector<unsigned int> &segTree) {
    if (i > r || j < l) {
        if (lazy[p])
            up(p, l, r, lazy, segTree);
        return;
    }
    else if (l >= i && r <= j) {
            appropLa(p, c, lazy);
            //maybe we should up the child first !!!
        if(lazy[p])
            up(p, l, r, lazy, segTree);
    }
    else {
        if (lazy[p])
            up(p, l, r, lazy, segTree);
        updateTree(p << 1, i, j, l, (l + r) / 2, c, lazy, segTree);
        updateTree((p << 1) + 1, i, j, (l + r) / 2 + 1, r, c, lazy, segTree);
        segTree[p] = segTree[p << 1] + segTree[(p << 1) + 1];
    }
}

unsigned int sum(int p, int l, int r, int i, int j, vector<char> &lazy, vector<unsigned int> &segTree) {
    if (l > j || i > r)
        return 0;
    if(lazy[p])
        up(p, l, r, lazy, segTree);
    if (i <= l && j >= r)
        return segTree[p];
    return sum(p << 1, l, (l + r) / 2, i, j, lazy, segTree) +
           sum((p << 1) + 1, (l + r) / 2 + 1, r, i, j, lazy, segTree);
}

unsigned int sum(int i, int j, string & pirates, vector<char> &lazy, vector<unsigned int> &segTree) {
    return sum(1, 0, pirates.size() - 1, i, j, lazy, segTree);
}

void updateTree(int i, int j, char c, string &pirates, vector<char> &lazy, vector<unsigned int> &segTree) {
    updateTree(1, i, j, 0, pirates.size() - 1, c, lazy, segTree);
}

int main() {
    int i = 1;
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        printf("Case %d:\n", i++);
        string pirates;
        int q = 1;
        int nPairs;
        scanf("%d", &nPairs);
        while (nPairs--) {
            int nTime;
            scanf("%d", &nTime);
            while (getchar() != '\n');
            char str[51];
            scanf("%s", str);
            for (int i = 0; i < nTime; i++)
                pirates += str;
        }
        vector<unsigned int> segTree(4 * (pirates.size()));
        vector<pair<int, int>> hllp(4 * pirates.size());
        vector<char> lazy(4 * pirates.size());
        buildTree(1, 0, pirates.size() - 1, segTree, pirates, hllp);
        int n;
        scanf("%d", &n);
        while (getchar() != '\n');
        while (n--) {
            char c = getchar();
            int i, j;
            scanf("%d%d", &i, &j);
            if (c == 'S') {
                printf("Q%d: ", q++);
                printf("%u\n", sum(i, j, pirates, lazy, segTree));
            }
            else
                updateTree(i, j, c, pirates, lazy, segTree);
            while (getchar() != '\n');
        }
        pirates[0] = '\0';
    }
    return 0;
}
