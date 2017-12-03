#include <iostream>
#include <string>
using namespace std;

template <class C> int solve(C beg,C end,int mask){
    return beg+1>=end?
          !!((*beg-'0')&mask)
          :(solve(beg,beg+(end-beg)/2,mask)<<((end-beg+1)/2))
          |(solve(beg+(end-beg)/2,end,mask));
}

int main(){
    string s; cin>>s;
    cout<<s.length()<<" "<<solve(s.begin(),s.end(),1)<<" "<<solve(s.begin(),s.end(),2)<<endl;
}
