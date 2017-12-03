#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> conn;
vector<int> match1, match2;
vector<bool> used;

bool match(int n) {
  if (used[n]) {
    return false;
  }
  used[n]=true;
  for (int i : conn[n]) {
    if (match2[i]==-1 || match(match2[i])) {
      match1[n]=i;
      match2[i]=n;
      return true;
    }    
  }
  return false;
}

int main() {
  int n;
  cin>>n;
  conn=vector<vector<int>>(n);
  map<long long, int> idx;
  vector<long long> as,bs,ans;
  for (int i=0; i<n; i++) {
    long long a,b;
    cin>>a>>b;
    as.push_back(a);
    bs.push_back(b);
    if (!idx.count(a+b)) {
      idx[a+b] = ans.size();
      ans.push_back(a+b);
    }
    conn[i].push_back(idx[a+b]);
    if (!idx.count(a-b)) {
      idx[a-b] = ans.size();
      ans.push_back(a-b);
    }
    conn[i].push_back(idx[a-b]);
    if (!idx.count(a*b)) {
      idx[a*b] = ans.size();
      ans.push_back(a*b);
    }
    conn[i].push_back(idx[a*b]);
  }
  match1=vector<int>(n,-1);
  match2=vector<int>(ans.size(),-1);
  bool ok=true;
  for (int i=0; i<n; i++) {
    used=vector<bool>(n,false);
    ok = ok && match(i);
  }
  if (!ok) {
    cout<<"impossible"<<endl;
    return 0;
  }
  for (int i=0; i<n; i++) {
    long long a=as[i],b=bs[i],c=ans[match1[i]];
    char op;
    if (a+b==c) op='+';
    if (a-b==c) op='-';
    if (a*b==c) op='*';
    cout<<a<<op<<b<<'='<<c<<endl;
  }  
  return 0;
}
