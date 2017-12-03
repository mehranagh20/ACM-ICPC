#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll const flag=(1ll<<50ll);

ll a[2500],b[2500];
map<ll,ll> assign,from;
queue<ll> todo;

int main(){
    int n; cin>>n;
    for (int i=0; i<n; i++) cin>>a[i]>>b[i];

    for (int changed=1; changed--; from.clear()){
        for (int i=n; i--;)
            if (not assign.count(i^flag))
                todo.push(from[i^flag]=i^flag);

        while (not todo.empty()){
            ll x=todo.front(); todo.pop();
            if (x>=flag){
                x^=flag;
                if (changed) continue;
                for (ll v: {a[x]+b[x],a[x]-b[x],a[x]*b[x]})
                    if (not from.count(v)){
                        from[v]=(x^flag);
                        todo.push(v);
                    }
            }
            else if (not assign.count(x)){
                vector<ll> path={x};
                while (from.count(path.back()) and path.back()!=from[path.back()]){
                    path.push_back(from[path.back()]);
                    from.erase(path[path.size()-2]);
                }
                if (from.count(path.back()) and path.back()==from[path.back()])
                    for (int z=0; z<path.size(); z+=2)
                        assign[assign[path[z]]=path[z+1]]=path[z];
                from.erase(path.back());
                changed=1;
            }
            else if (not changed and not from.count(assign[x]))
                todo.push(assign[from[assign[x]]=x]);
        }
    }

    if (assign.size()!=n*2)
        cout<<"impossible"<<endl;
    else for (int i=0; i<n; i++)
        cout<<a[i]<<(assign[i^flag]==a[i]+b[i]? '+': assign[i^flag]==a[i]-b[i]? '-': '*')<<b[i]<<'='<<assign[i^flag]<<endl;
}
