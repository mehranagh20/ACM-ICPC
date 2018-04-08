#include <stdio.h>
#include <vector>

using namespace std;

vector<int> sets;

void buildSets(int n)
{
    sets.resize(n + 1);
    for(int i = 1; i <= n; i++)
        sets[i] = i;
}

int findSet(int i)
{
    return (sets[i] == i ? i : findSet(sets[i]));
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void merge(int i, int j)
{
    if(!isSameSet(i, j))
    {
        int a = findSet(i);
        int b = findSet(j);
        if(a < b)
            sets[b] = a;
        else
            sets[a] = b;
    }
}

int main() {
    int n, j = 0;
    scanf("%d", &n);
    while(n--)
    {
        if(j++)
            puts("");
        int corr = 0, inCorr = 0;
        int nCom;
        scanf("%d", &nCom);
        buildSets(nCom);
        while(getchar() != '\n');
        char c = getchar();
        while(c != '\n' && c != ' ' && c != EOF)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            if(c == 'c')
                merge(i, j);
            else
                isSameSet(i, j) ? corr++ : inCorr++;
            while(getchar() != '\n');
            c = getchar();
        }
        printf("%d,%d\n", corr, inCorr);
    }

    return 0;
}
