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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

double pi = acos(-1.);

double degToRad(double theta){ return theta * pi / 180.0; }

dd rotate(dd p, double theta) {
    double rad = degToRad(theta);
    return dd(p.first * cos(rad) - p.second * sin(rad),
              p.first * sin(rad) + p.second * cos(rad));
}

double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main() {
    ios::sync_with_stdio(0);
    int l, c, r1, r2;
    while(cin >> l >> c >> r1 >> r2 && (l || c || r1 || r2)) {
        if(r1 < r2) swap(r1, r2);
        double x1 = -r1, y1 = r1, x2 = l - r1, y2 = r1 - c;
        double low = 0, high = 360;
        dd initial = dd(-(r1 + r2), 0);
        bool pos = false;
        while(fabs(high - low) > eps) {
            double mid = (high + low) / 2;
            dd newq = rotate(initial, mid);
            double dis = dist(newq, dd(0, 0));
            if(!(newq.first - x1 + eps >= r2 && newq.second - y2 + eps >= r2))
                low = mid;
            else if(!(x2 - newq.first + eps >= r2 &&  y1 - newq.second + eps >= r2))
                high = mid;
            else {
                pos = true;
                break;
            }
        }
        if(2 * r1 > l || 2 * r1 > c || 2 * r2 > l || 2 * r2 > c) pos = false;
        if(pos) cout << "S" << endl;
        else cout << "N" << endl;
    }


    return 0;
}
