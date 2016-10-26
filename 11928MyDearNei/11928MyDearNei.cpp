#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        vector<pair<int, int>> order;
        int nNei;
        scanf("%d\n", &nNei);
        for(int i = 1; i <= nNei; i++) {
            int j = 0, tmp;
            char c = 'f';
            while (c != '\n') {
                scanf("%d", &tmp);
                j++;
                c = getchar();
            }
            order.push_back(make_pair(j, i));
        }
        sort(order.begin(), order.end());
        printf("%d", order[0].second);
        nNei = 1;
        while(order[nNei].first == order[0].first)
            printf(" %d",order[nNei++].second);
        puts("");
    }
    return 0;
}