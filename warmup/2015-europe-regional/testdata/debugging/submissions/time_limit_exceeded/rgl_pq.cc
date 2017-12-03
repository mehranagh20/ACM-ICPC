#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
ll res[2000002];
vector<ll> evt[2000002]={{},{},{1ll<<60ll}};

int main(){
    ll n,t,p; cin>>n>>t>>p;
    map<ll,ll> have;

    for (ll i=2; i<=n; i++){
        for (ll x: evt[i]){
            if (x>=0 and not ++have[x]) have.erase(x);
            if (x<-0 and not --have[~x]) have.erase(~x);
        }
        res[i]=min(t+p*i-p,have.begin()->first);

        if (res[i]>res[i-1]){
            if (1!=--i) for (ll j=2; i*j<=n*2; j++){
                ll val=res[i]+(j-1)*p+t;
                evt[max(j, i*j+1  )].push_back(~val);
            }
            ++i;

            for (ll j=2; i*j<=n*2; j++){
                ll val=res[i]+(j-1)*p+t;
                evt[max(j, i*j+1-j)].push_back( val);
            }
        }
    }

    cout<<res[n]<<endl;
}
