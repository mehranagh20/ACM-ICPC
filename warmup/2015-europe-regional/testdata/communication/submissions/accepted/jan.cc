#include <iostream>

using namespace std;

int main() {
  int obf[256];
  for (int x=0; x<256; x++) {
    obf[x ^ (((x << 1) & 255))] = x;
  }
  bool first=true;
  int n;
  cin>>n;
  while (n--) {
    int x;
    cin>>x;
    if (first) {
      first=false;
    } else {
      cout<<" ";
    }
    cout<<obf[x];
  }
  cout<<endl;    
  return 0;
}
