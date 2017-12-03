#include <algorithm>
#include <iostream>
using namespace std; typedef long long ll;
ll res[1000001];

int main(){
    ll n,t,p; cin>>n>>t>>p;

    for (ll i=2; (res[i]=res[i-1]+p+t), i<=n; i++)
        for (ll j=2; j<=i; j++)
            res[i]=min(res[i],res[(i+j-1)/j]+(j-1)*p+t);

    cout<<res[n]<<endl;
}
