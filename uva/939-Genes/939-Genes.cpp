//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string ts, tts;
    map<string, vector<string>> ind;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ts >> tts;
        if (tts == "non-existent" || tts == "recessive" || tts == "dominant") {
            vector<string> tmpV = {"", "", tts};
            ind[ts] = tmpV;
        }
        else
            ind[tts].push_back(ts);
    }
    bool still = true;
    while (still) {
        still = false;
        for (auto itt = ind.begin(); itt != ind.end(); itt++) {
            if (itt->second.size() == 2) {
                still = true;
                if(ind[itt->second[0]].size() > 2 && ind[itt->second[1]].size() > 2) {
                    auto it = itt;
                    if ((ind[it->second[0]][2] == "recessive" && ind[it->second[1]][2] == "recessive") ||
                        (ind[it->second[0]][2] == "dominant" && ind[it->second[1]][2] != "recessive") && ind[it->second[1]][2] != "dominant" ||
                        (ind[it->second[1]][2] == "dominant" && ind[it->second[0]][2] != "recessive" &&
                         ind[it->second[0]][2] != "dominant"))
                        it->second.push_back("recessive");
                    else if ((ind[it->second[0]][2] == "dominant" && ind[it->second[1]][2] == "dominant") ||
                             (ind[it->second[0]][2] == "dominant" && ind[it->second[1]][2] == "recessive") ||
                             (ind[it->second[0]][2] == "recessive" && ind[it->second[1]][2] == "dominant"))
                        it->second.push_back("dominant");
                    else it->second.push_back("non-existent");
                }
            }
        }
    }
    for (auto it = ind.begin(); it != ind.end(); it++) cout << it->first << " " << it->second[2] << endl;

    return 0;
}