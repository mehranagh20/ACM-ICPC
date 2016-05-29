#include <stdio.h>
#include <set>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        multiset<int> bills;
        long long int paidTillNow = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            while(k--)
            {
                int tmp;
                scanf("%d", &tmp);
                bills.insert(tmp);
            }
            paidTillNow += (*bills.rbegin() - *bills.begin());
            bills.erase(bills.find(*bills.rbegin()));
            bills.erase(bills.begin());
        }
        printf("%lld\n", paidTillNow);
    }

    return 0;
}