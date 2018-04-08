#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, i = 0;
    cin >> n;
    while (n--) {
        if(i++)
            cout << endl;
        multiset<int> grAr, blAr;
        int batt, nG, nB, mG = 0, mB = 0, tmp;
        cin >> batt >> nG >> nB;
        while (nG--) {
            cin >> tmp;
            grAr.insert(tmp);
            mG += tmp;
        }
        while (nB--) {
            cin >> tmp;
            blAr.insert(tmp);
            mB += tmp;
        }
        if (mB == mG)
            cout << "green and blue died" << endl;
        else {
            vector<int> gTmp, bTmp;
            while (!grAr.empty() && !blAr.empty()) {
                for (int i = 0; i < batt; i++) {
                    if(grAr.empty() && blAr.empty())
                        break;
                    if (!grAr.empty()) {
                        gTmp.push_back(*grAr.rbegin());
                        grAr.erase(grAr.find(*grAr.rbegin()));
                    }
                    if (!blAr.empty()) {
                        bTmp.push_back(*blAr.rbegin());
                        blAr.erase(blAr.find(*blAr.rbegin()));
                    }
                }
                int minS;
                if(bTmp.size() < gTmp.size())
                    minS = bTmp.size();
                else
                    minS = gTmp.size();
                for(int i = 0; i < minS; i++)
                {
                    if(bTmp[i] <= gTmp[i])
                    {
                        gTmp[i] -= bTmp[i];
                        bTmp[i] = 0;
                    }
                    else
                    {
                        bTmp[i] -= gTmp[i];
                        gTmp[i] = 0;
                    }
                }
                for(auto & e : bTmp)
                    if(e)
                        blAr.insert(e);
                for(auto & e : gTmp)
                    if(e)
                        grAr.insert(e);
                bTmp.clear();
                gTmp.clear();
            }
            if(mG > mB)
            {
                cout << "green wins" << endl;
                for(multiset<int>::reverse_iterator it = grAr.rbegin(); it != grAr.rend(); it++)
                    cout << *it << endl;
            }
            else
            {
                cout << "blue wins" << endl;
                for(multiset<int>::reverse_iterator it = blAr.rbegin(); it != blAr.rend(); it++)
                    cout << *it << endl;
            }
        }
    }

    return 0;
}