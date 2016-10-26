//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8

map<int, string> mp = {{2, "Tanveer Ahsan"}, {5, "Shahriar Manzoor"}, {7, "Adrian Kugel"}, {11, "Anton Maydell"}, {15, "Derek Kisman"}, {20, "Rezaul Alam Chowdhury"},
                       {28, "Jimmy Mardell"}, {36, "Monirul Hasan"}};

bool isDev(string s, int sec) {
    string dev = "";
    int rem = 0, start = 0;
    for (int i = 0; i < s.size(); i++) {
        rem = s[i] - '0' + 10 * rem;
        if (rem / sec) start = 1;
        if (start) dev += (rem / sec) + '0';
        rem = rem % sec;
    }
    return !rem;
}

int main() {
    ios::sync_with_stdio(0);
    string s, ss;
    int tc = 0;
    while(cin >> ss && ss != "0") {
        s.clear();
        if (tc++) cout << endl;
        cout << ss << endl;
        if(ss.size() > 4 || (ss.size() == 4 && ss > "2148")) {
            string tmp;
            int i;
            if(ss.size() > 19) {
                i = ss.size() - 19;
                while(ss[i] == '0') i++;
            }
            else i = 0;
            for(int j = 0; j < i; j++) s += ss[j];
            for(i; i < ss.size(); i++) tmp += ss[i];
            unsigned long long tmpNum = strtoull(tmp.c_str(), NULL, NULL) - 2148;
            s += to_string(tmpNum);
            auto it = mp.begin();
            bool gost = false;
            while (it != mp.end()) {
                if (isDev(s, it->first)) {
                    gost = true;
                    cout << "Ghost of " << it->second << "!!!" << endl;
                }
                it++;
            }
            if ((!isDev(ss, 100) && isDev(ss, 4)) || (isDev(ss, 400))) cout << "Ghost of K. M. Iftekhar!!!\n";
            else if (!gost) cout << "No ghost will come in this year\n";
        }
        else cout << "No ghost will come in this year\n";

    }

    return 0;
}