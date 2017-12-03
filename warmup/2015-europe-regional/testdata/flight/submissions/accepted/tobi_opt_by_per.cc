#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define TORAD(X) (2.*acos(0)*(X)/180.)
#define norm(X) (sqrt(dot(X,X)))
#define dot(P1,P2) (P1[0]*P2[0] + P1[1]*P2[1] + P1[2]*P2[2])
int C, N[51];
double P[51][51][2], totLen, watLen, way1[3], way2[3], v1[3], v2[3];

void toCart(double *P, double *cart) {
	cart[0] = sin(P[0]) * cos(P[1]);
	cart[1] = sin(P[0]) * sin(P[1]);
	cart[2] = cos(P[0]);
}

double distC(double *V1, double *V2) {
	return 6370*acos(dot(V1, V2));
}
	
int main() {
	cin >> C;
	FOR(i, 0, C+1) { // last "continent" is flight plan
		cin >> N[i];
		FOR(j, 0, N[i]) FOR(k, 0, 2) {
			cin >> P[i][j][k];
			if (k == 0) P[i][j][k] += 90;
			P[i][j][k] = TORAD(P[i][j][k]);
		}
	}
	bool inside = true;
	toCart(P[C][0], way2);
	FOR(i, 0, N[C]-1) {
		FOR(j, 0, 3) way1[j] = way2[j];
		toCart(P[C][i+1], way2);
		vector<double> alldists;
		FOR(j, 0, C) FOR(k, 0, N[j]) {
			toCart(P[j][k], v1);
			toCart(P[j][(k+1)%N[j]], v2);
			double alpha = 0, omega = 1, fullDst = distC(way1, way2), mid[2], v[2][3], diff[2], bestDiff = 500000, retD;
			FOR(i, 0, 50) {
				FOR(j, 0, 2) {
					mid[j] = alpha + (1+j)*(omega-alpha)/3.;
					FOR(k, 0, 3) v[j][k] = v1[k] + mid[j]*(v2[k] - v1[k]);
					double len = norm(v[j]);
					FOR(k, 0, 3) v[j][k] /= len;
					diff[j] = abs(fullDst - distC(v[j], way1) - distC(v[j], way2));
				}
				if (diff[0] < diff[1]) omega = mid[1];
				else alpha = mid[0];
				retD = distC(v[0], way1);
				bestDiff = min(bestDiff, min(diff[0], diff[1]));
			}
			if (bestDiff < 0.000001) alldists.push_back(retD);
		}
		sort(alldists.begin(), alldists.end());
		totLen += distC(way1, way2);
		double last = 0;
		for (int i = 0; i < alldists.size(); inside = !inside, last = alldists[i], i++) {
			if (!inside) watLen += alldists[i] - last;
		}
		if (!inside) watLen += distC(way1, way2) - last;
	}
	cout << setprecision(20) << totLen << " " << (100.*watLen/totLen) << endl;
	return 0;
}
