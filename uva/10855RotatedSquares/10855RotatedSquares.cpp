#include <iostream>
#include <vector>

using namespace std;

void acc(vector<string> &big, vector<string> &small, int &num)
{
    for(int j = 0; j < big.size() - small.size() + 1; j++)
    {
        for(int i = 0; i < big.size() - small.size() + 1; i++)
        {
            bool isEq = true;
            for(int k = j; k < j + small.size(); k++)
            {
                for(int d = i; d < i + small.size(); d++)
                {
                    if(big[d][k] != small[d - i][k - j])
                    {
                        isEq = false;
                        break;
                    }
                }
                if(!isEq)
                    break;
                if(k == j + small.size() - 1)
                    num++;
            }
        }
    }
}

int main() {
    int N, n;
    while(cin >> N >> n && N)
    {
        while(getchar() != '\n');
        vector<string> big(N), small(n);
        for(int i = 0; i < N; i++)
            getline(cin, big[i]);
        for(int i = 0; i < n; i++)
            getline(cin, small[i]);
        int num = 0;
        for(int i = 0; i < 4; i++)
        {
            vector<string> tmp(n);
            acc(big, small, num);
            cout << num;
            if (i != 3)
                cout << " ";
            for(int j = 0; j < n; j++)
                for(int k = n  - 1; k >= 0; k--)
                    tmp[j].push_back(small[k][j]);
            num = 0;
            small = tmp;
        }
        cout << endl;

    }
    return 0;
}
