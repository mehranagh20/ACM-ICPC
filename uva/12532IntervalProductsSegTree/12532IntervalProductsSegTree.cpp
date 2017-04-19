#include <stdio.h>
#include <langinfo.h>

int segTree[400040], nums[100010];


void buildTree(int p, int l, int r) {
    if (l == r)
        segTree[p] = nums[l];
    else {
        buildTree(p << 1, l, (l + r) / 2);
        buildTree((p << 1) + 1, (l + r) / 2 + 1, r);
        segTree[p] = segTree[p << 1] * segTree[(p << 1) + 1];
    }
}

void up(int p, int l, int r, int i, int val)
{
    if(l > i || r < i)
        return;
    if(l == r)
        segTree[p] = val;
    else {
        up(p << 1, l, (l + r) / 2, i, val);
        up((p << 1) + 1, (l + r) / 2 + 1, r, i, val);
        segTree[p] = segTree[p << 1] * segTree[(p << 1) + 1];
    }
}

int mRQ(int p, int l, int r, int i, int j) {
    if (l > j || r < i)
        return 1;
    if (l >= i && r <= j)
        return segTree[p];
    return (mRQ(p << 1, l, (l + r) / 2, i, j) * mRQ((p << 1) + 1, (l + r) / 2 + 1, r, i, j));
}

int main() {
    int nNum, q;
    while(scanf("%d%d", &nNum, &q) != EOF){
        int i = 1;
        for(; i <= nNum; i++) {
            int tmp;
            scanf("%d", &tmp);
            if(!tmp)
                nums[i] = 0;
            else if(tmp < 0)
                nums[i] = -1;
            else
                nums[i] = 1;
        }
        while(getchar() != '\n');
        buildTree(1, 1, nNum);
        while(q--)
        {
            int i, j;
            char c;
            scanf("%c%d%d", &c, &i, &j);
            if(c == 'C') {
                if(j < 0)
                    j = -1;
                else if(j > 0)
                    j = 1;
                else
                    j = 0;
                up(1, 1, nNum, i, j);
            }
            else
            {
                int product = mRQ(1, 1, nNum, i, j);
                if(!product)
                    printf("0");
                else if(product < 0)
                    printf("-");
                else
                    printf("+");
            }
            while(getchar() != '\n');
        }
        printf("\n");
    }

    return 0;
}
