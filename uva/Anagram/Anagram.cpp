#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, caseNum = 0;
    cin >> n;
    while (getchar() != '\n');
    while (getchar() != '\n');
    while (caseNum++ != n) {
        if (caseNum > 1)
            cout << endl;
        string tmp, tmp2;
        vector<string> list;
        vector<string> rList;
        while (getline(cin, tmp2)) {
            for (int i = 0; i < tmp2.size(); i++)
                if (!isspace(tmp2[i]))
                    tmp.push_back(tmp2[i]);
            if (tmp2.empty())
                break;
            list.push_back(tmp);
            rList.push_back(tmp2);
            tmp = "";
            tmp2 = "";
        }
        for (int i = 0; i < rList.size(); i++)
            for (int j = 0; j < rList.size() - 1; j++)
                if (rList[j] > rList[j + 1]) {
                    string tmp = rList[j];
                    rList[j] = rList[j + 1];
                    rList[j + 1] = tmp;
                    tmp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = tmp;
                }
        vector<vector<bool>> isAl(list.size(), vector<bool>(list.size(), false));
        vector<string> fList;
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (isAl[i][j])
                    continue;
                bool isAnag = true;
                if (j == i)
                    continue;
                isAl[i][j] = true;
                isAl[j][i] = true;
                if (list[i].size() != list[j].size())
                    continue;
                for (int k = 0; k < list[i].size(); k++) {
                    if(list[j].find(list[i][k]) == string::npos) {
                        isAnag = false;
                        break;
                    }
                    int tmpHlp = 1, tmpHlp2 = 0;
                    for(int d = 0; d < list[i].size(); d++) {
                        if (d != k && list[i][k] == list[i][d])
                            tmpHlp++;
                        if(list[i][k] == list[j][d])
                            tmpHlp2++;
                    }
                    if(tmpHlp2 != tmpHlp) {
                        isAnag = false;
                        break;
                    }
                }
                if (isAnag) {
                    tmp = rList[i] + " = " + rList[j];
                    cout << tmp;
                    cout << endl;
                }

            }

        }
    }

        return 0;
    }
