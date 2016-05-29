#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> vec(m);
        vector<vector<int>> order(m);
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;
            if (r) {
                vector<int> ver(m, 0);
                for (int i = 0; i < r; i++) {
                    int tmp;
                    cin >> tmp;
                    ver[tmp - 1] = 1;
                }
                for (int i = 0; i < m; i++) {
                    if (ver[i]) {
                        int tmp;
                        cin >> tmp;
                        vec[i].push_back(tmp);
                        order[i].push_back(vec[i].size());
                    }
                    else
                        vec[i].push_back(0);
                }
            }
            else
                for (int i = 0; i < m; i++)
                    vec[i].push_back(0);
        }
        cout << m << " " << n << endl;
        for (int i = 0; i < m; i++) {
            cout << order[i].size();
            if(order[i].size())
                cout << " ";
            for (int j = 0; j < order[i].size(); j++) {
                cout << order[i][j];
                if (j != order[i].size() - 1)
                    cout << " ";
            }
            cout << endl;
            int tmp = 0;
            for (int j = 0; j < vec[i].size(); j++) {
                if (vec[i][j]) {
                    if(tmp++)
                        cout << " ";
                    cout << vec[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}