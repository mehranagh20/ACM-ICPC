#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
  int r,s,m,d,n;
  cin>>r>>s>>m>>d>>n;
  vector<int> brands(r);
  for (int i=0; i<r; i++) {
    cin >> brands[i];
  }
  vector<vector<int>> dish(s+m+d);
  for (int i=0; i<s+m+d; i++) {
    int x;
    cin>>x;
    dish[i]=vector<int>(x);
    for (int j=0; j<x; j++) {
      cin>>dish[i][j];
      dish[i][j]--;
    }
  }
  set<pair<int,int>> bad;
  for (int i=0; i<n; i++) {
    int x,y;
    cin>>x>>y;
    x--; y--;
    if (x>y) swap(x,y);
    bad.insert(make_pair(x,y));
  }
  long long answer = 0;
  double approx = 0.0;   
  for (int i=0; i<s; i++) {
    for (int j=s; j<s+m; j++) {
      if (bad.count(make_pair(i,j))) continue;
      for (int k=s+m; k<s+m+d; k++) {
	if (bad.count(make_pair(i,k))) continue;
	if (bad.count(make_pair(j,k))) continue;
	set<int> ingr;
	for (int x : dish[i]) ingr.insert(x);
	for (int x : dish[j]) ingr.insert(x);
	for (int x : dish[k]) ingr.insert(x);
	long long add = 1;
	double approx_add = 1.0;
	for (int x : ingr) {
	  add *= brands[x];
	  approx_add *= brands[x];
	}
	answer += add;
	approx += approx_add;
      }
    }
  }
  if (approx <= 1.1e18 && answer <= (long long) 1e18) {
    cout << answer << endl;
  } else {
    cout << "too many" << endl;
  }
  return 0;
}
