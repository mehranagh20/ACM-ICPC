//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef pair<int, int> pii;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<pii> logins;
    multiset<int> available;
    rep(i,0,n)
    {
      int a, b;
      scanf("%d %d", &a, &b);
      logins.push_back(pii(a, a + b));
    }

    int res = 0;
    sort(logins.begin(), logins.end());
    rep(i,0,n)
    {
      while (!available.empty() && *available.begin() + m < logins[i].first)
        available.erase(available.begin());

      if (!available.empty() && *available.begin() <= logins[i].first)
      {
        available.erase(available.begin());
        res++;
      }

      available.insert(logins[i].second);
    }
    cout << res << endl;
}
