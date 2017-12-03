#include <iostream>
#include <vector>

using namespace std;

vector<int> permute(vector<int> a, vector<int> b) {
  int n = a.size();
  vector<int> ainv(n);
  for (int i=0; i<n; i++) {
    ainv[a[i]-1] = i;
  }
  vector<int> c(n);
  for(int i=0; i<n; i++) {
    c[i] = ainv[b[i] - 1];
  }
  return c;
}

long long numswaps(vector<int>& a) {
  if (a.size() == 1) return 0;
  vector<int> left = vector<int>(a.begin(), a.begin() + a.size() / 2);
  vector<int> right = vector<int>(a.begin() + a.size() / 2, a.end());
  long long swaps = numswaps(left) + numswaps(right);
  a.clear();
  int i=0, j=0;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      a.push_back(left[i++]);
    } else {
      a.push_back(right[j++]);
      swaps += left.size() - i;
    }
  }
  while (i < left.size()) {
    a.push_back(left[i++]);
  }
  while (j < right.size()) {
    a.push_back(right[j++]);
  }
  return swaps;
}

int main() {
  long long n;
  cin>>n;
  vector<int> a(n),b(n),c(n);
  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<n; i++) cin>>b[i];
  for (int i=0; i<n; i++) cin>>c[i];
  vector<int> ab = permute(a,b);
  vector<int> ac = permute(a,c);
  vector<int> bc = permute(b,c);
  cout << (n*(n-1) - numswaps(ab) - numswaps(ac) - numswaps(bc)) / 2 << endl;
  return 0;
}
