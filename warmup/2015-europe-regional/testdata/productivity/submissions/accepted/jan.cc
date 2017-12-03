#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int infty = 999999999;

struct interval {
  int fr, to;
};
  
int main() {
  int num_workers, num_lines;
  cin >> num_workers >> num_lines;
  vector<interval> workers(num_workers);
  for (int i=0; i<num_workers; i++) {
    cin >> workers[i].fr >> workers[i].to;
  }
  vector<interval> first;
  vector<interval> extra;
  for (int i=0; i<num_workers; i++) {
    bool is_covering = false;
    for (int j=0; j<num_workers; j++) {
      if (workers[j].fr >= workers[i].fr && workers[j].to <= workers[i].to) {
	if (workers[j].fr > workers[i].fr || workers[j].to < workers[i].to) {
	  is_covering = true;
	} else {
	  if (i > j) is_covering = true;	    
	}
      }
    }
    if (is_covering) {
      extra.push_back(workers[i]);
    } else {
      first.push_back(workers[i]);
    }
  }
  sort(first.begin(), first.end(), [&] (const interval& a, const interval& b) { return a.fr < b.fr; });
  sort(extra.begin(), extra.end(), [&] (const interval& a, const interval& b) { return a.to-a.fr > b.to-b.fr; });
  vector<vector<int>> intersection(first.size(), vector<int>(first.size(), -infty));
  for (int i=0; i<first.size(); i++) {
    int fr=-infty, to=infty;
    for (int j=i; j<first.size(); j++) {
      fr = max(fr, first[j].fr);
      to = min(to, first[j].to);
      if (to-fr > 0) {
	intersection[i][j] = to-fr;
      } else {
	break;
      }
    }
  }
  vector<vector<int>> best(num_lines+1, vector<int>(first.size()+1, -infty));
  best[0][0] = 0;
  for (int i=0; i<num_lines; i++) {
    for (int j=0; j<first.size(); j++) {
      for (int k=j; k<first.size(); k++) {
	best[i+1][k+1] = max(best[i+1][k+1], best[i][j] + intersection[j][k]);
      }
    }
  }
  int add = 0;
  int result = 0;
  for (int i=0; i<=min(num_lines, (int)extra.size()); i++) {
    result = max(result, best[num_lines-i][first.size()] + add);
    if (i < extra.size()) {
      add += extra[i].to - extra[i].fr;
    }
  }
  cout << result << endl;
  return 0;
}
