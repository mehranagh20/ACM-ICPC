#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string str;
    int nC = 1;
    while(getline(cin, str) && str != "end")
    {
       vector<stack<char>> st;
        for(auto & c : str)
        {
            if(st.size())
            {
                bool found = false;
                for(auto & e : st)
                    if(e.top() >= c)
                    {
                        e.push(c);
                        found = true;
                        break;
                    }
                if(!found)
                {
                    stack<char> tmp;
                    tmp.push(c);
                    st.push_back(tmp);
                }
            }
            else
            {
                stack<char> tmp;
                tmp.push(c);
                st.push_back(tmp);
            }
        }
        cout << "Case " << nC++ << ": " <<st.size() << endl;

    }
}