#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

bool comp(pair <int , int> a , pair <int , int> b){
    return a.first < b.first;
}

int main (){
    int tc;
    cin >> tc;
    while (tc--){
        int s, f;
        vector <pair<int, int> > jobs;
        int maxmeeting = 0;
        while (cin >> s >> f){
            if (s == 0 && f == 0) break;
            jobs.push_back(make_pair(s, f));
        }
        sort(jobs.begin(), jobs.end() , comp);

        for (int ctr = 0 ; ctr < pow(2 , (int)jobs.size()) ; ctr++){
            int tempctr = ctr;
//            cerr << ctr << endl;
            vector <int> injobs;
            for (int i = 1 , j = 0; i <= tempctr ; i <<= 1 ,j++){
                if ((tempctr & i ) != 0){
//                    cerr << "inside" << endl;
//                    cerr << tempctr << " " << i << endl;
                    injobs.push_back(j);
                }
//                cerr << "outside" << endl;
            }

            int valid = true;
            for (int i = 0 ; i < (int)injobs.size() - 1 ; i++){
                if (jobs[injobs[i]].second > jobs[injobs[i + 1]].first){
                    valid = false;
                    break;
                }
            }
            if (valid){
                maxmeeting = max (maxmeeting , (int)injobs.size());
            }
        }
        cout << maxmeeting << endl;
    }


    return 0;
}