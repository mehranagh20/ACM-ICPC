#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n,t;
  cin>>n>>t;
  vector<pair<int,int>> x(n);
  for (int i=0; i<n; i++) {
    cin>>x[i].first>>x[i].second;
  }
  sort(x.begin(),x.end());
  
  int sol=0;
  priority_queue<int> pq;
  for (int i=0; i<n; i++) {
    while (!pq.empty()) {
      int next = -pq.top();
      if (x[i].first < next) {
	break;
      }
      pq.pop();
      if (x[i].first <= next+t) {
	sol++;
	break;
      }
    }
    pq.push(-(x[i].first+x[i].second));
  }

  cout << sol << endl;
  return 0;
}
