#include <iostream>
#include <cstdlib>
using namespace std;

string convert_to_quadkey(int x,int y,int depth){
    string res;
    while (depth--) res+=char('0'+(!!(x&(1<<depth)))+(2*!!(y&(1<<depth))));
    return res;
}

int score(int x,int y,int depth,string const &a){
    string b=convert_to_quadkey(x,y,depth);
    int score=0;
    for (int i=0; i<a.length(); i++){
        score+=__builtin_popcount(a[i]&b[i]);
    }
    return score;
}

int main(){
    string key; cin>>key;
    int depth=key.length();
    int x=0,y=0;
    for (int iter=100000; iter--;){
        int mutate=(1<<(rand()%depth));
        if (score(x^mutate,y,depth,key)>score(x,y,depth,key)){
            x^=mutate;
        }
        if (score(x,y^mutate,depth,key)>score(x,y,depth,key)){
            y^=mutate;
        }
    }
    cout<<depth<<" "<<x<<" "<<y<<endl;
}
