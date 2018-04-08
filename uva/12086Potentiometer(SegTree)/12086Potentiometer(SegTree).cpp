#include <stdio.h>

int potmeters[200000];
int segTree[600000];

void buildSegTree(int p, int l, int r) {
    if (l == r)
        segTree[p] = potmeters[l];
    else {
        buildSegTree(p << 1, l, (l + r) / 2);
        buildSegTree((p << 1) + 1, (l + r) / 2 + 1, r);
        segTree[p] = segTree[p << 1] + segTree[(p << 1) + 1];
    }
}

void updateSegTree(int p, int l, int r, int i, int val) {
    if (l > i || r < i)
        return;
    if (l == r)
        segTree[p] = val;
    else {
        updateSegTree(p << 1, l, (l + r) / 2, i, val);
        updateSegTree((p << 1) + 1, (l + r) / 2 + 1, r, i, val);
        segTree[p] = segTree[p << 1] + segTree[(p << 1) + 1];
    }
}

int sumQuery(int p, int l, int r, int i, int j) {
    if (l > j || r < i)
        return 0;
    if (l >= i && r <= j)
        return segTree[p];
    return sumQuery(p << 1, l, (l + r) / 2, i, j) + sumQuery((p << 1) + 1, (l + r) / 2 + 1, r, i, j);
}

int main() {
    int n, caseNum = 1;
    while (scanf("%d", &n) && n) {
        if(caseNum > 1)
            puts("");
        printf("Case %d:\n", caseNum++);
        int i = 1;
        for (i; i <= n; i++)
            scanf("%d", &potmeters[i]);
        buildSegTree(1, 0, n);
        while (getchar() != '\n');
        char command = getchar();
        while (command != 'E') {
            int i, j;
            scanf("%d%d", &i, &j);
            if (command == 'M')
                printf("%d\n", sumQuery(1, 0, n, i, j));
            else
                updateSegTree(1, 0, n, i, j);
            while (getchar() != '\n');
            command = getchar();
        }
        while (getchar() != '\n');

    }

    return 0;
}