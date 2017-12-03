#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

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
  if (((b.p-a.p)*(a.q-a.p)) * ((b.q-a.p)*(a.q-a.p)) > 0) return false;
  if (((a.p-b.p)*(b.q-b.p)) * ((a.q-b.p)*(b.q-b.p)) > 0) return false;
  return true;  
}

void flip(int& coord, int mirror) {
  coord = 2 * mirror - coord;
}

void flip(point& p, line mirror) {
  if (mirror.p.x == mirror.q.x) {
    flip(p.x, mirror.p.x);
  } else {
    flip(p.y, mirror.p.y);
  }
}

void flip(vector<line>& walls, line mirror) {
  for (line& wall : walls) {
    flip(wall.p, mirror);
    flip(wall.q, mirror);
  }
}

int main() {
  int num_walls;
  point origin;
  origin.x = 0;
  origin.y = 0;
  point hole;  
  cin >> num_walls >> hole.x >> hole.y;
  vector<line> walls(num_walls);
  for (int i=0; i<num_walls; i++) {
    cin >> walls[i].p.x >> walls[i].p.y >> walls[i].q.x >> walls[i].q.y;
  }
  vector<int> perm;
  for (int i=0; i<num_walls; i++) {
    perm.push_back(i);
  }
  int result = -1;
  do {
    point virtual_hole = hole;
    vector<line> virtual_walls = walls;
    for (int num_hits=0; num_hits<=num_walls; num_hits++) {
      bool ok = true;
      line trajectory;
      trajectory.p = origin;
      trajectory.q = virtual_hole;
      double angle = atan2(virtual_hole.y, virtual_hole.x);
      vector<line> check_walls = walls;
      set<int> disappeared;
      double prev_distance = 0.0;
      for (int hit=0; hit<=num_hits; hit++) {
	double closest = 1e99;
	int wall_hit = -1;
	for (int i=0; i<num_walls; i++) {
	  if (disappeared.count(i)) continue;
	  line wall = check_walls[i];
	  if (intersect(trajectory, wall)) {
	    double dist;
	    if (wall.p.x == wall.q.x) {
	      dist = fabs(wall.p.x / cos(angle));
	    } else {
	      dist = fabs(wall.p.y / sin(angle));
	    }
	    if (dist > prev_distance && dist < closest) {
	      closest = dist;
	      wall_hit = i;
	    }	      
	  }	  
	}
	if (hit < num_hits && wall_hit != perm[hit]) {
	  ok = false;
	  break;
	}
	if (hit == num_hits && wall_hit != -1) {
	  ok = false;
	  break;
	}
	if (hit < num_hits) {
	  flip(check_walls, check_walls[perm[hit]]);
	  disappeared.insert(perm[hit]);
	  prev_distance = closest;
	}
      }
      if (ok) {
	result = max(result, num_hits);
      }
      if (num_hits < num_walls) {
	line mirror = virtual_walls[perm[num_hits]];
	flip(virtual_hole, mirror);
	flip(virtual_walls, mirror);
      }
    }
  } while(next_permutation(perm.begin(), perm.end()));
  if (result >= 0) {
    cout << result << endl;
  } else {
    cout << "impossible" << endl;
  }  
  return 0;
}
