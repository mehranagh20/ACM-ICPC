#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const double R = 6370.0;
const double eps = 1e-9;

struct point {
  double x,y,z;
};

double operator* (point p, point q) {
  return p.x*q.x + p.y*q.y + p.z*q.z;
}

point operator* (double a, point p) {
  p.x *= a;
  p.y *= a;
  p.z *= a;
  return p;
}

point operator^ (point p, point q) {
  point r;
  r.x = p.y*q.z - q.y*p.z;
  r.y = p.z*q.x - q.z*p.x;
  r.z = p.x*q.y - q.x*p.y;
  return r;
}

point normalize(point p) {
  double length = sqrt(p * p);
  return (1.0 / length) * p;
}

vector<point> readline() {
  int n;
  cin>>n;
  vector<point> ps;
  for (int i=0; i<n; i++) {
    double theta, phi;
    cin >> theta >> phi;
    theta *= 2.0 * M_PI / 360.0;
    phi *= 2.0 * M_PI / 360.0;
    point p;
    p.x = cos(theta) * cos(phi);
    p.y = cos(theta) * sin(phi);
    p.z = sin(theta);
    ps.push_back(p);
  }
  return ps;
}

double distance(point p, point q) {
  double cos_angle = p * q;
  if (cos_angle > 1.0) cos_angle = 1.0;
  if (cos_angle < -1.0) cos_angle = -1.0;
  double angle = acos(cos_angle);
  if (angle > M_PI) angle = 2*M_PI - angle;
  return angle;  
}

int main() {
  int numcontinents;
  cin >> numcontinents;
  vector<vector<point>> continents(numcontinents);
  for (int i=0; i<numcontinents; i++) {
    continents[i] = readline();
  }
  vector<point> route = readline();
  double totaldistance = 0.0;
  vector<double> intersects;
  for (int i=0; i+1<route.size(); i++) {
    point normal1 = normalize(route[i] ^ route[i+1]);
    for (vector<point> continent : continents) {
      for (int j=0; j<continent.size(); j++) {
	int j2 = (j+1) % continent.size();
	point normal2 = normalize(continent[j] ^ continent[j2]);
	point normal3 = normal1 ^ normal2;
	if (normal3 * normal3 == 0.0) continue;
	normal3 = normalize(normal3);
	for (int sign : { -1, 1 }) {
	  point intersect = sign * normal3;
	  if (distance(intersect, route[i]) + distance(intersect, route[i+1])
	      > distance(route[i], route[i+1]) + eps) continue;
	  if (distance(intersect, continent[j]) + distance(intersect, continent[j2])
	      > distance(continent[j], continent[j2]) + eps) continue;
	  intersects.push_back(totaldistance + distance(intersect, route[i]));
	}
      }
    }
    totaldistance += distance(route[i], route[i+1]);
  }
  sort(intersects.begin(), intersects.end());
  double waterdistance = 0.0;
  for (int i=0; i<intersects.size(); i+=2) {
    waterdistance += intersects[i+1] - intersects[i];
  }
  cout << setprecision(10) <<  R * totaldistance << " "
       << 100.0 * waterdistance / totaldistance << endl;
  return 0;
}
