//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

double triangleArea(double a, double b, double c){
    double s = (a + b + c) / 2;
    return (sqrt(s) * sqrt(s - a) * sqrt(s - b) * sqrt(s - c));
}

double rInCircle(double a, double b, double c) {
    return triangleArea(a, b, c) / (0.5 * (a + b + c));
}

double rCircumCircle(double a, double b, double c) {
    return a * b * c / (4.0 * triangleArea(a, b, c));
}

int main() {
    ios::sync_with_stdio(0);
    double a, b, c;
    while(cin >> a >> b >> c) {
        double triangle_area = triangleArea(a, b, c), outter = pow(rCircumCircle(a, b, c), 2) * acos(-1.), inner = pow(rInCircle(a, b, c), 2) * acos(-1.);
        cout << fixed << setprecision(4) << outter - triangle_area << " " << triangle_area - inner << " " << inner << endl;
    }

    return 0;
}
