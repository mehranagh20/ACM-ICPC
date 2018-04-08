#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, i = 1;
    while (cin >> n && n != 0) {
        cout << "Case " << i++ << ":" << endl;
        string tmp;
        vector<string> listOfStrs;
        while (n--) {
            cin >> tmp;
            listOfStrs.push_back(tmp);
        }
        for (int i = 0; i < listOfStrs.size(); i++) {
            int tmp = 1, rNum;
            for (int j = i + 1; j < listOfStrs.size(); j++) {
                int k = 0;
                for (k; k < listOfStrs[i].size(); k++)
                    if (listOfStrs[i][k] != listOfStrs[j][k])
                        break;
                string str1 = listOfStrs[i]. substr(k), str2 = listOfStrs[j].substr(k);
                int num1 = stoi(str1);
                int num2 = stoi(str2);
                if (num1 + tmp != num2)
                    break;
                else {
                    tmp++;
                    rNum = num1;
                }
            }
            cout << listOfStrs[i];
            if(tmp > 1)
                cout << "-" << rNum + tmp - 1 << endl;
            else
                cout << endl;
            i += tmp - 1;
        }
        cout << endl;
    }

    return 0;
}