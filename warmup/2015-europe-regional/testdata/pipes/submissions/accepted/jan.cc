#include <iostream>
#include <vector>

using namespace std;

struct point {
  int x,y;
};

struct line {
  point p,q;
};

point operator - (point a, point b) {
  point c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}

int operator * (point a, point b) {
  int c = a.x * b.y - b.x * a.y;
  return c == 0 ? 0 : c / abs(c);
}

bool intersect(line a, line b) {
  if (a.p.x == b.p.x && a.p.y == b.p.y) {
    return false;
  }
  if (((b.p-a.p)*(a.q-a.p)) * ((b.q-a.p)*(a.q-a.p)) > 0) return false;
  if (((a.p-b.p)*(b.q-b.p)) * ((a.q-b.p)*(b.q-b.p)) > 0) return false;
  return true;  
}

vector<int> state;
vector<vector<int>> conn;

bool possible(int n, int s) {
  if (state[n] != -1) {
    return state[n] == s;
  }
  state[n] = s;
  for (int i : conn[n]) {
    if (!possible(i, 1-s)) {
      return false;
    }    
  }
  return true;
}

int main() {
  int numwells, numpipes;
  cin >> numwells >> numpipes;
  vector<point> wells(numwells);
  for (int i=0; i<numwells; i++) {
    cin >> wells[i].x >> wells[i].y;
  }
  vector<line> pipes(numpipes);
  for (int i=0; i<numpipes; i++) {
    int well;
    cin >> well >> pipes[i].q.x >> pipes[i].q.y;
    pipes[i].p = wells[well-1];
  }
  conn = vector<vector<int>>(numpipes);
  for (int i=0; i<numpipes; i++) {
    for (int j=0; j<numpipes; j++) {
      if (intersect(pipes[i], pipes[j])) {
	conn[i].push_back(j);
      }
    }
  }
  bool pos = true;
  state = vector<int>(numpipes, -1);
  for (int i=0; i<numpipes; i++) {
    if (state[i]==-1 && !possible(i, 0)) {
      pos = false;
      break;
    }
  }
  cout << (pos ? "possible" : "impossible") << endl;      
  return 0;
}
