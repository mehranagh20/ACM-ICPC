#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nCourse, nCat;
    while(cin >> nCourse && nCourse != 0)
    {
        bool isYes = true;
        cin >> nCat;
        vector<int> coursesTaken(nCourse);
        while(--nCourse >= 0)
            cin >>coursesTaken[nCourse];
        while(nCat--)
        {
            int met = 0, min, tmp;
            cin >> nCourse >> min;
            if(isYes) {
                while (nCourse--) {
                    cin >> tmp;
                    if (met < min) {
                        for (auto &e : coursesTaken)
                            if (e == tmp) {
                                met++;
                                break;
                            }
                    }
                }
            }
            else
            {
                while(nCourse--)
                    cin >> tmp;
            }
            if(met < min)
                isYes = false;
        }
        if(isYes)
            cout << "yes" <<endl;
        else
            cout << "no" << endl;
    }

    return 0;
}