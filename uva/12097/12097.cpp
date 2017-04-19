#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std; 

vector <double> cakes;

bool isValid (double size , int f){
	int res = 0;
	for (int i = cakes.size() - 1 ; i >= 0 ; i--){
		res += floor (cakes[i] / size);
	}
	return res >= f;
}

int main (){
	int t; cin >> t;
	while (t--){
		int n; int f; 
		cin >> n >> f;

		f++;
		cakes = vector <double> (n , 0);
		for (int i = 0 ; i < n ; i++) {cin >> cakes[i]; cakes[i] *= (cakes[i] * (acos(-1)));}

		sort (cakes.begin() , cakes.end());
		double _min = 0;
		double _max = cakes.back();

		while (_min <= _max - 0.0001){
			double mid = (_min + _max) / 2;
			if (!isValid(mid , f)){
				_max = mid;
			}
			else {
				_min = mid;
			}
		}
		cout << setprecision (4) << fixed << _min << endl;
	}

	return 0;
}