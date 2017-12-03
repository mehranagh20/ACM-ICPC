#include <iostream>
#include <string>
#include <map>
using namespace std;

// convert an arbitrary x/y coordinate into a partial quadkey string
string convert_to_quadkey(int x, int depth, int factor){
    string res;
    while (depth--) res+=char('0'+factor*!!(x&(1<<depth)));
    return res;
}

// take the difference of a from b (quadkey needed to go b->a)
string subtract(string a,string b){
    for (int i=0; i<a.length(); i++){
        a[i]-=b[i]-'0';
    }
    return a;
}

// combine two quadkey strings
string add(string a,string b){
    for (int i=0; i<a.length(); i++){
        a[i]+=b[i]-'0';
    }
    return a;
}

// create all possible quadkeys for the integers in the given range and step
map<string,int> generate_possibilities(int from, int to, int basis, int length, int factor){
    map<string,int> res;
    for (int i=from; i<to; i+=basis){
        res[convert_to_quadkey(i, length, factor)]=i;
    }
    return res;
}

int main(){
    string s; cin>>s;
    int n=s.length();
    int m=n/2;

    // Print depth
    cout<<n<<" ";

    // Split S into two separate strings: one for X, one for Y
    string sx=s; for (auto &i: sx) i&=~('2'^'0');
    string sy=s; for (auto &i: sy) i&=~('1'^'0');

    // Compute possible halves of X
    auto x_lo=generate_possibilities(0, (1<<m),      1, n, 1);
    auto x_hi=generate_possibilities(0, (1<<n), (1<<m), n, 1);

    // Match up X-halves for full X
    for (auto i: x_lo){
        if (x_hi.count(subtract(sx, i.first))){
            cout<<i.second+x_hi[subtract(sx, i.first)]<<" ";
            break;
        }
    }

    // Compute possible halves of Y
    auto y_lo=generate_possibilities(0, (1<<m),      1, n, 2);
    auto y_hi=generate_possibilities(0, (1<<n), (1<<m), n, 2);

    // Match up Y-halves for full Y
    for (auto i: y_lo){
        if (y_hi.count(subtract(sy, i.first))){
            cout<<i.second+y_hi[subtract(sy, i.first)]<<endl;
            break;
        }
    }
}
