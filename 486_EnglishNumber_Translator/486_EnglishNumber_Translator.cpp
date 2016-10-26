//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
#define inf 1000000000

int main() {
    ios::sync_with_stdio(0);
    vector<string> vNum = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                           "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                           "nineteen",
                           "twenty"};
    map<string, int> strToNum, bigs = {{"hundred",  100},
                                       {"thousand", 1000},
                                       {"million",  1000000}};
    for (int i = 0; i <= 20; i++) strToNum.insert(make_pair(vNum[i], i));
    vNum = {"thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    for (int i = 3; i < 3 + vNum.size(); i++) strToNum.insert(make_pair(vNum[i - 3], i * 10));
    string s;
    while (true) {
        getline(cin, s);
        if (cin.eof()) break;
        stringstream ss(s);
        string tmpS;
        ss >> tmpS;
        int num = 0, coef = 1;
        if (tmpS == "negative") {
            coef = -1;
            ss >> tmpS;
        }
        bool h = true;
        size_t p;
        if((p = s.find("million")) != s.npos) {
            int curr = 0;
            while(true) {
                if(strToNum.find(tmpS) != strToNum.end())
                    curr += strToNum[tmpS];
                else if(bigs.find(tmpS) != bigs.end() && tmpS != "million")
                    curr *= bigs[tmpS];
                else if(tmpS == "million") break;
                ss >> tmpS;
            }
            num += curr * 1000000;
            if(ss >> tmpS) h = true;
            else h = false;
        }
        size_t tmpP = p;
        if((p = s.find("thousand", p + 1)) != s.npos) {
            int curr = 0;
            while(h) {
                if(strToNum.find(tmpS) != strToNum.end())
                    curr += strToNum[tmpS];
                else if(bigs.find(tmpS) != bigs.end() && tmpS != "thousand")
                    curr *= bigs[tmpS];
                else if(tmpS == "thousand") break;
                ss >> tmpS;
            }
            num += curr * 1000;
            if(ss >> tmpS)
                h = true;
            else h = false;
        }
        else p = tmpP;
        int curr = 0;
        while(true) {
            if(strToNum.find(tmpS) != strToNum.end())
                curr += strToNum[tmpS];
            else if(bigs.find(tmpS) != bigs.end())
                curr *= bigs[tmpS];
            if(!(ss >> tmpS)) break;
        }
        num += curr;
        cout << coef * num << endl;
    }
    return 0;
}
