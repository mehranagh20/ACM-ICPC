#include <stdio.h>

int potmeters[200010];
int fenwickTree[200010];

void inc(int i, int val, int n)
{
    for(i; i <= n; i += (i & -i))
        fenwickTree[i] += val;
}

void buildFenTree(int n)
{
    int i = 1;
    for(i; i <= n; i++) {
        inc(i, potmeters[i], n);
    }
}

int sum(int a)
{
    int sum = 0;
    for(; a; a -= (a & -a))
        sum += fenwickTree[a];
    return sum ;
}
int rSum(int a, int b)
{
    return sum(b) - (a == 1 ? 0 : sum(a - 1));
}

int main() {
    int n, caseNum = 1;
    while (scanf("%d", &n) && n) {
        if(caseNum > 1)
            puts("");
        printf("Case %d:\n", caseNum++);
        int i = 1;
        for (i; i <= n; i++) {
            scanf("%d", &potmeters[i]);
            fenwickTree[i] = 0;
        }
        buildFenTree(n);
        while (getchar() != '\n');
        char command = getchar();
        while (command != 'E') {
            int i, j;
            scanf("%d%d", &i, &j);
            if(command == 'S') {
                inc(i, j - potmeters[i], n);
                potmeters[i] = j;
            }
            else
                printf("%d\n", rSum(i, j));
            while (getchar() != '\n');
            command = getchar();
        }
        while (getchar() != '\n');

    }

    return 0;
}