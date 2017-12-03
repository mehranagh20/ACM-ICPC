//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
  int n, p; cin >> n >> p;
  vector<pii> a, b;
  rep(i,0,n)
  {
    int x, y;
    cin >> x >> y;
    a.push_back({x, -y});
  }

  sort(a.begin(), a.end());
  rep(i,0,a.size()) a[i].second *= -1;
  int ma = 123456789;
  vi lengths;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i].second < ma)
      b.push_back(a[i]);
    else
      lengths.push_back(a[i].second - a[i].first);
    ma = min(ma, a[i].second);
  }

  reverse(b.begin(), b.end());
  int best[b.size() + 1][p + 1];
  memset(best, 0xff, sizeof(best));

  best[0][0] = 0;
  rep(i,0,b.size()) rep(j,0,p)
    if (best[i][j] >= 0)
  {
    rep(k,i,b.size())
    {
      int l = b[i].second - b[k].first;
      if (l <= 0) break;
      best[k + 1][j + 1] = max(best[k + 1][j + 1], best[i][j] + l);
    }
  }

  sort(lengths.begin(), lengths.end(), greater<int> ());

  int res = best[b.size()][p], sum = 0;
  rep(i,0,p)
    if (i < lengths.size())
    {
      sum += lengths[i];
      if (best[b.size()][p - i - 1] >= 0)
        res = max(res, best[b.size()][p - i - 1] + sum);
    }
  cout << res << endl;
}
