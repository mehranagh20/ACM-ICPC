#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<int, int> mp;
    vector<int> vec;
    int tmp;
    while(scanf("%d", &tmp) != EOF) {
        if(mp.find(tmp) == mp.end()) {
            mp.insert(make_pair(tmp, 1));
            vec.push_back(tmp);
        }
        else
            mp[tmp]++;
    }
    for(auto & e : vec)
        printf("%d %d\n", e, mp[e]);
    return 0;
}