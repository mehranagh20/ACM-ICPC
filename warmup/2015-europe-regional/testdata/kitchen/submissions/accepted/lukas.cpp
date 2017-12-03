#include <iostream>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
  int r, s, m, d, n;
  cin >> r >> s >> m >> d >> n;

  vi b(r);
  rep(i,0,r) cin >> b[i];

  vector<vi> ingred(s+m+d);
  rep(i,0,s+m+d)
  {
    int k; cin >> k;
    vi ing(k);
    rep(j,0,k)
      cin >> ing[j];
    ingred[i] = ing;
  }

  set<pii> forb;
  rep(i,0,n)
  {
    int x, y; cin >> x >> y;
    x--; y--;
    if (x > y) swap(x, y);
    forb.insert({x, y});
  }

  double rd = 0;
  ll res = 0;
  rep(ii,0,s) rep(jj,0,m) rep(kk,0,d)
  {
    int i = ii;
    int j = jj + s;
    int k = kk + s + m;
    if (forb.count({i, j}) || forb.count({i, k}) || forb.count({j, k}))
      continue;

    set<int> ing;
    ing.insert(ingred[i].begin(), ingred[i].end());
    ing.insert(ingred[j].begin(), ingred[j].end());
    ing.insert(ingred[k].begin(), ingred[k].end());
    ll tmp = 1; double td = 1;
    for (int w : ing)
      tmp *= b[w - 1], td *= b[w - 1];
    res += tmp;
    rd += td;
  }

  if (rd > 1.1e18 || res > 1000000000000000000LL)
    cout << "too many" << endl;
  else
    cout << res << endl;
}
