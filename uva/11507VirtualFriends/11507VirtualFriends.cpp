#include <stdio.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

string findSet(string &a, map<string, pair<string, int>> &mp) {
    string tmp = mp[a].first;
    vector<string> t;
    while(tmp != a) {
        t.push_back(a);
        a = tmp;
        tmp = mp[a].first;
    }
    for(auto & e : t)
        mp[e].first = tmp;
    return tmp;
}

string merge(string &a, string &b, map<string, pair<string, int>> &mp) {
    string tmp1 = findSet(a, mp), tmp2 = findSet(b, mp);
    if (tmp1 != tmp2) {
        tmp1 < tmp2 ? mp[tmp2].first = tmp1 : mp[tmp1].first = tmp2;
        mp[tmp1].second += mp[tmp2].second;
        mp[tmp2].second = mp[tmp1].second;
    }
    return tmp1;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        map<string, pair<string, int>> connections;
        int nCon;
        scanf("%d\n", &nCon);
        for (int i = 0; i < nCon; i++) {
            char a[21], b[21];
            scanf("%s%s", a, b);
            string tmp1 = a, tmp2 = b;
            if (connections.find(tmp1) == connections.end())
                connections.insert(make_pair(tmp1, make_pair(tmp1, 1)));
            if (connections.find(tmp2) == connections.end())
                connections.insert(make_pair(tmp2, make_pair(tmp2, 1)));
            printf("%d\n", connections[merge(tmp1, tmp2, connections);].second);
            while (getchar() != '\n');
        }
    }
    return 0;
}
