// Author: Es'hagh Moutabi

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long int ans(long long int,long long int);
int main()
{
  int n;
  cin>> n;
while(n!=0){
  vector<int> vi(n);
  for (int i = 0; i < vi.size(); i++) {
    vi[i]=i+1;
  }
  if (n!=1) {
  cout<<"Discarded cards:";
    while (vi.size()!=1)
    {
    cout<<" "<<vi[0];
    vi.erase(vi.begin());
    if (vi.size()==1){
      cout<<endl;
     //cerr<<vi.size()<<endl;
        cout<<"Remaining card: "<<vi[0]<<endl;
    }

        if (vi.size()>1){
          vi.push_back(vi[0]);

          cout<<",";
      vi.erase(vi.begin());
      }
    }
  }
  else if(n==1){
    cout<<"Discarded cards:"<<endl;
    cout<<"Remaining card: "<<vi[0]<<endl;
  }
    cin>> n;

  }
return 0;
}
