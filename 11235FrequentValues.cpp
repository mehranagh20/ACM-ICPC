#include <stdio.h>

int segTree[400040], nums[100010];


void buildTree(int p, int l, int r) {
    if (l == r)
        segTree[p] = nums[l];
    else {
        buildTree(p << 1, l, (l + r) / 2);
        buildTree((p << 1) + 1, (l + r) / 2 + 1, r);
        if (segTree[p << 1] > segTree[(p << 1) + 1]) {
            segTree[p] = segTree[p << 1];
        }
        else
            segTree[p] = segTree[(p << 1) + 1];
    }
}

int mRQ(int p, int l, int r, int i, int j) {
    if (l > j || r < i)
        return -1;
    if (l >= i && r <= j)
        return segTree[p];
    int tmp1 = mRQ(p << 1, l, (l + r) / 2, i, j), tmp2 = mRQ((p << 1) + 1, (l + r) / 2 + 1, r, i, j);
    return (tmp1 > tmp2 ? tmp1 : tmp2);
}

int main() {
    int n, q;
    while (scanf("%d", &n) && n) {
        scanf("%d", &q);
        int tmp1, tmp2, i = 1;
        scanf("%d", &tmp2);
        nums[1] = i++;
        int j = 2;
        for (; j <= n; j++) {
            scanf("%d", &tmp1);
            if (tmp1 == tmp2)
                nums[j] = i++;
            else {
                i = 1;
                tmp2 = tmp1;
                nums[j] = i++;
            }
        }
        buildTree(1, 1, n);
        while (q--) {
            int i, j, max = 0;
            scanf("%d%d", &i, &j);
            if (i == j)
                max = 1;
            else if (nums[i] > 1) {
                int tmpI = i;
                while (nums[i] > 1 && i < j)
                    i++;
                if (i == j && nums[j] > 1)
                    max = j - tmpI + 1;
                else
                    max = i - tmpI;
            }
            if (j - i) {
                int mMax = mRQ(1, 1, n, i, j);
                if (mMax > max)
                    max = mMax;
            }
            printf("%d\n", max);
        }
    }
    return 0;
}
