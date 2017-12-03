#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <map>
using namespace std;

pair<int,int> v[250000];
map<int,pair<int,int>> evt;
queue<int> available;

int main(){
    int n,m; cin>>n>>m;
    for (++n; --n;) {int a,b; cin>>a>>b; ++evt[a].first, ++evt[a+b].second;}
    for (auto i: evt){
        while (not available.empty() and available.front()<i.first) available.pop();
        while (i.second.second--) available.push(i.first+m);
        while (i.second.first--) if (not available.empty()) ++n, available.pop();
    }
    cout<<n<<endl;
}
