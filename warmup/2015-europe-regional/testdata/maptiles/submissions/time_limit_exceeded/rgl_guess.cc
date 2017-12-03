#include <iostream>
#include <cstdlib>
using namespace std;

string convert_to_quadkey(int x,int y,int depth){
    string res;
    while (depth--) res+=char('0'+(!!(x&(1<<depth)))+(2*!!(y&(1<<depth))));
    return res;
}

int main(){
    string key; cin>>key;
    int depth=key.length();
    int x=0,y=0;
    while (convert_to_quadkey(x,y,depth)!=key){
        x=rand()%(1<<depth);
        y=rand()%(1<<depth);
    }
    cout<<depth<<" "<<x<<" "<<y<<endl;
}
