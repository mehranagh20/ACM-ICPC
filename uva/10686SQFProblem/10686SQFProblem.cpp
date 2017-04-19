#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        vector<string> catOrder;
        int nCat;
        scanf("%d", &nCat);
        while(getchar() != '\n');
        string catName;
        map<string, pair<int, int>> cattegoryMp;
        map<string, set<string>> tmpMap;
        while (nCat--) {
            int nKey, nec;
            cin >> catName >> nKey >> nec;
            catOrder.push_back(catName);
            while (nKey--) {
                string tmpStr;
                cin >> tmpStr;
                if (tmpMap.find(tmpStr) == tmpMap.end()) {
                    set<string> tmpSet;
                    tmpSet.insert(catName);
                    tmpMap.insert(make_pair(tmpStr, tmpSet));
                }
                tmpMap[tmpStr].insert(catName);
            }
            cattegoryMp.insert(make_pair(catName, make_pair(0, nec)));
            if(!nCat)
                getline(cin, catName);
        }
        string txt, tmpStr;
        set<string> allWords;
        while (getline(cin, tmpStr) && !tmpStr.empty())
            txt += tmpStr + " ";
        for(int i = 0; i < txt.size(); i++)
            if(!isalpha(txt[i]))
                txt[i] = ' ';
        istringstream i (txt);
        while(i >> tmpStr)
            allWords.insert(tmpStr);
        for(auto e = allWords.begin(); e != allWords.end(); e++)
            if(tmpMap.find(*e) != tmpMap.end()) {
                for (auto ee = tmpMap[*e].begin(); ee != tmpMap[*e].end(); ee++) {
                    cattegoryMp[*ee].first++;
                }
            }
        int sp = 0;
        for (auto &e : catOrder) {
            if (cattegoryMp[e].first >= cattegoryMp[e].second) {
                if (sp++)
                    printf(",");
                cout << e;
            }
        }
        if (!sp)
            printf("SQF Problem.");
        puts("");
    }

    return 0;
}