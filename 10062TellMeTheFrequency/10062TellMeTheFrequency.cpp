#include <stdio.h>
#include <vector>

using namespace std;

int main() {
   int c;
    int k = 0;
    vector<int>tmp(150, 0);
    vector<int> val(150, 0);
    vector<int> asc(150);
    while((c = getchar()) != EOF)
    {
        if(c != '\n')
        {
            asc[c] = c;
            val[c]++;
        }
        else
        {
            if(k++ > 0)
                puts("");
            for(int i = 0; i < val.size(); i++)
                for(int j = 0; j < val.size() - 1; j++)
                    if(val[j] < val[j + 1])
                    {
                        swap(val[j + 1], val[j]);
                        swap(asc[j + 1], asc[j]);
                    }
            int i = 0;
            while(val[i])
                i++;
            for(int j = i - 1; j >= 0; j--)
                printf("%d %d\n", asc[j], val[j]);
            val = tmp;
            asc.clear();
        }
    }

}