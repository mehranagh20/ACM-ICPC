#include <iostream>

using namespace std;

#define sz(c) int((c).size())
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main(){
	string s; cin >> s;
	s = string(s.rbegin(), s.rend());
	int x = 0; int y = 0;
	FOR(i,0,sz(s)){
		x |= (1<<i) * ((s[i]-'0')%2);
		y |= (1<<i) * ((s[i]-'0')/2);
	}
	
	cout << sz(s) << " " << x << " " << y << endl;
}

















