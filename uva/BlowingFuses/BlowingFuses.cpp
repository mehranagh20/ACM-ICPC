#include <iostream>
#include <vector>

using namespace std;

int main() {
   int nDevices, nOper, cap, caseNum = 0;
    while(cin >> nDevices >> nOper >> cap && (nDevices != 0 || nOper != 0 || cap != 0))
    {
        caseNum++;
        int curr = 0, max = -1;
        vector<int> devAmp(nDevices);
        vector<bool> isOn(nDevices,false);
        for(int i = 0; i < nDevices; i++)
            cin >> devAmp[i];
        int tmp;
        while(nOper--)
        {
            cin >> tmp;
            if(isOn[tmp - 1]) {
                curr -= devAmp[tmp - 1];
                isOn[tmp - 1] = false;
            }
            else
            {
                curr += devAmp[tmp - 1];
                isOn[tmp - 1] = true;
                if(curr > max)
                {
                    max = curr;
                }
            }

        }

        if(max > cap)
            cout << "Sequence " << caseNum << endl <<"Fuse was blown." << endl <<endl;
        else
            cout << "Sequence " << caseNum << endl << "Fuse was not blown." << endl << "Maximal power consumption was " << max << " amperes." << endl << endl;

    }

    return 0;
}