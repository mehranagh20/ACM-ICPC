#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
    int arr[8], n, m, a, b, seatsApart, dis[8][8];
    for (int i = 0; i < 8; i++)
        arr[i] = i;
    while (scanf("%d%d", &n, &m) && (n || m)) {
        int numOfDif = 0;
        map<int, vector<pair<int, int>>> constrains;
        while (m--) {
            scanf("%d%d%d", &a, &b, &seatsApart);
            if (constrains.find(a) != constrains.end())
                constrains[a].push_back(make_pair(b, seatsApart));
            else if (constrains.find(b) != constrains.end())
                constrains[b].push_back(make_pair(a, seatsApart));
            else {
                vector<pair<int, int>> tmp = {make_pair(b, seatsApart)};
                constrains.insert(make_pair(a, tmp));
            }
        }
        if (!m) {
            int tmp = 1;
            while(n--)
                tmp *= n;
            numOfDif = tmp;
        }
        else
            do {
                bool isOk = true;
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        dis[arr[i]][arr[j]] = j - i;
                        dis[arr[j]][arr[i]] = j - i;
                    }
                    if (constrains.find(arr[i]) != constrains.end())
                        for (auto &e : constrains[arr[i]]) {
                            if (e.second < 0) {
                                if (abs(e.second) > dis[arr[i]][e.first]) {
                                    isOk = false;
                                    break;
                                }
                            }
                            else {
                                if (e.second < dis[arr[i]][e.first]) {
                                    isOk = false;
                                    break;
                                }
                            }
                        }
                    if (!isOk)
                        break;
                }
                if (isOk)
                    numOfDif++;
            } while (next_permutation(arr, arr + n));
        printf("%d\n", numOfDif);
    }
}