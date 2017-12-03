//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int main()
{
  string s; cin >> s;
  cout << s.size() << " ";
  int x = 0, y = 0;
  for (char c : s)
  {
    x *= 2; y *= 2;
    if (c > '1')
      x++;
    if (((c - '0') & 1) == 1)
      y++;
  }

  cout << y << " " << x << endl;
}
