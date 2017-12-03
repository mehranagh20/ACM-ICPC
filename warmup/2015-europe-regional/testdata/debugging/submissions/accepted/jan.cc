#include <iostream>
#include <vector>

using namespace std;

long long compile, print;
vector<long long> cache;

long long solve(int lines) {
  if (lines==1) return 0;
  long long& sol = cache[lines];
  if (sol != -1) return sol;
  sol = compile + lines * print;
  for (int i=1; i<=lines; i++) {
    sol = min(sol, compile + i*print + solve((lines+i)/(i+1)));
  }
  return sol;
}

int main() {
  int lines;
  cin >> lines >> compile >> print;
  cache = vector<long long>(lines+1, -1);
  cout << solve(lines) << endl;
  return 0;
}
