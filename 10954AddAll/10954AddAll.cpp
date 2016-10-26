#include <stdio.h>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const unsigned int &l, const unsigned int &r) {
        return l > r;
    }
};

int main() {
    int n;
    while(scanf("%d", &n) && n)
    {
        priority_queue <unsigned int, vector<unsigned int>, compare> prio;
        for(int i = 0; i < n; i++)
        {
            unsigned int tmp;
            scanf("%u", &tmp);
            prio.push(tmp);
        }
        int tmp = prio.size();
        unsigned int cost = 0;
        for(int i = 0; i < tmp - 1; i++)
        {
            unsigned int t = prio.top();
            prio.pop();
            unsigned int t2 = prio.top();
            prio.pop();
            cost += t + t2;
            prio.push(t + t2);
        }
        printf("%u\n", cost);

    }


    return 0;
}