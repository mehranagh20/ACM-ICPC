#include <bits/stdc++.h>
using namespace std;

const double pi = 2*acos(0), eps = 1e-9;

struct pnt {
	double x, y, z;

	pnt(double lat = 0, double lon = 0) {
		lat *= pi/180, lon *= pi/180;
		x = cos(lat)*cos(lon);
		y = cos(lat)*sin(lon);
		z = sin(lat);
	}

	void normalize() {
		double len = sqrt(x*x + y*y + z*z);
		x /= len, y /= len, z /= len;
	}
};

double dist(pnt a, pnt b) {
	return acos(a.x*b.x + a.y*b.y + a.z*b.z);
}

pnt cross(pnt p, pnt q) {
	pnt res;
	res.x = p.y*q.z - p.z*q.y;
	res.y = p.z*q.x - p.x*q.z;
	res.z = p.x*q.y - p.y*q.x;
	res.normalize();
	return res;
}

bool intersect(pnt a, pnt b, pnt c, pnt d, pnt &s) {
	s = cross(cross(a,b),cross(c,d));
	if (std::isnan(dist(a,s))) return false;
	if (std::isnan(dist(b,s))) return false;
	if (std::isnan(dist(c,s))) return false;
	if (std::isnan(dist(d,s))) return false;
	if (abs(dist(a,s)+dist(s,b)-dist(a,b)) > eps) s.x = -s.x, s.y = -s.y, s.z = -s.z;
	if (abs(dist(a,s)+dist(s,b)-dist(a,b)) > eps) return false;
	if (abs(dist(c,s)+dist(s,d)-dist(c,d)) > eps) return false;
	return true;
}

int main() {
	int m; cin >> m;
	vector<vector<pnt>> p(m+1);
	for (int i = 0; i <= m; i++) {
		int n; cin >> n;
		p[i].resize(n);
		for (int j = 0; j < n; j++) {
			double lat, lon; cin >> lat >> lon;
			p[i][j] = pnt(lat,lon);
		}	
	}
	
	bool inside = true;
	double len = 0, res = 0;
	for (int k = 1; k < p[m].size(); k++) {
		len += dist(p[m][k-1],p[m][k]);
		vector<pnt> v = { p[m][k-1], p[m][k] };
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= p[i].size(); j++) {
				pnt s;
				if (intersect(p[m][k-1],p[m][k],p[i][j-1],p[i][j%p[i].size()],s))
					v.push_back(s);
			}
		}
		sort(begin(v),end(v),[&](const pnt &a, const pnt &b) {
			return dist(p[m][k-1],a) < dist(p[m][k-1],b);
		});
		for (int i = 1; i < v.size(); i++) {
			if (!inside) res += dist(v[i-1],v[i]);
			if (i+1 < v.size()) inside = !inside;
		}
	}
	res /= len, res *= 100;
	len *= 6370;
	cout << fixed << setprecision(12) << len << " " << res << endl;
}

