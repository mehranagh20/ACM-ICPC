#include <bits/stdc++.h>

using namespace std;

int main() {
    char arr1[6][5], arr2[6][5];
    int t, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &k);
        while(getchar() != '\n');
        for(int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%c", &arr1[i][j]);
            }
            while(getchar() != '\n');
        }
        for(int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%c", &arr2[i][j]);
            }
            while(getchar() != '\n');
        }
        map<string, bool> mp;
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                for(int k = 0; k < 6; k++)
                    for(int d = 0; d < 6; d++)
                        for(int t = 0; t < 6; t++) {
                            string str;
                            str += arr1[i][0];str += arr1[j][1];str += arr1[k][2];str += arr1[d][3];str += arr1[t][4];
                            mp.insert(make_pair(str, false));
                        }
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                for(int k = 0; k < 6; k++)
                    for(int d = 0; d < 6; d++)
                        for(int t = 0; t < 6; t++) {
                            string str;
                            str += arr2[i][0];str += arr2[j][1];str += arr2[k][2];str += arr2[d][3];str += arr2[t][4];
                            if(mp.find(str) != mp.end())
                                mp[str] = true;
                        }
        int i = 0;
        auto it = mp.begin();
        while(i != k && it != mp.end()) {
            if(it->second)
                i++;
            it++;
        }
        it--;
        if(i == k)
        cout << it->first << endl;
        else printf("NO\n");
    }
    return 0;
}