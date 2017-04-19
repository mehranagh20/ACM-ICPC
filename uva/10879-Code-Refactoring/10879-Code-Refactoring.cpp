//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8

string DRep, BAns;
vector<vector<char>> arr;
int ind;
char c;

void DtoB(int i, int j, int k, int d) {
    vector<vector<char>> &a = arr;
    if(DRep[ind] == '0' || DRep[ind] == '1')
        for (int f = i; f <= k; f++) for (int s = j; s <= d; s++)
                arr[f][s] = DRep[ind];
    else {
        int iTmp = (k + i) / 2;
        int jTmp = (d + j) / 2;
        if(i == k) {
            ind++; cin >> c; DRep += c;
            DtoB(i, j, iTmp, jTmp);
            ind++; cin >> c; DRep += c;
            DtoB(i, jTmp + 1, iTmp, d);
        }
        else if(j == d) {
            ind++; cin >> c; DRep += c;
            DtoB(i, j, iTmp, jTmp);
            ind++; cin >> c; DRep += c;
            DtoB(iTmp + 1, j, k, jTmp);
        }
        else {
            ind++; cin >> c; DRep += c;
            DtoB(i, j, iTmp, jTmp);
            ind++; cin >> c; DRep += c;
            DtoB(i, jTmp + 1, iTmp, d);
            ind++; cin >> c; DRep += c;
            DtoB(iTmp + 1, j, k, jTmp);
            ind++; cin >> c; DRep += c;
            DtoB(iTmp + 1, jTmp + 1, k, d);
        }
    }
}

void BtoD(int i, int j, int k, int d) {
    char c = arr[i][j];
    bool isOk = true;
    for(int f = i; f <= k; f++) for(int s = j; s <= d; s++)
            if(c != arr[f][s]) {
                isOk = false;
                break;
            }
    if(isOk) {
        BAns += c;
        return;
    };
    BAns += 'D';
    int iTmp = (k + i) / 2;
    int jTmp = (d + j) / 2;
    if(i == k) {
        BtoD(i, j, iTmp, jTmp);
        BtoD(i, jTmp + 1, iTmp, d);
    }
    else if(j == d) {
        BtoD(i, j, iTmp, jTmp);
        BtoD(iTmp + 1, j, k, jTmp);
    }
    else {
        BtoD(i, j, iTmp, jTmp);
        BtoD(i, jTmp + 1, iTmp, d);
        BtoD(iTmp + 1, j, k, jTmp);
        BtoD(iTmp + 1, jTmp + 1, k, d);
    }
}

int main() {
    //ios::sync_with_stdio(0);
    char c; int m, n;
    while(cin >> c && c != '#') {
        cin >> m >> n;
        arr.clear(); arr.resize(m, vector<char>(n));
        if(c == 'D') {
            DRep.clear();
            string tmp; char c;
            cin >> c; DRep += c;
//            while(DRep.size() < m * n) {
//                cin >> tmp;
//                DRep += tmp;
//            }
            ind = 0;
            DtoB(0, 0, m - 1, n - 1);
            cout << "B" << setw(4) << m << setw(4) << n << endl;
            int tn = 0;
            for(int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << arr[i][j];
                    tn++;
                    if(!(tn % 50) && tn < m * n)
                        cout << endl;
                }
            }
            cout << endl;
        }
        else {
            BAns.clear();
            for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
                    cin >> arr[i][j];
            BtoD(0, 0, m - 1, n - 1);
            cout << "D" << setw(4) << m << setw(4) << n << endl;
            for(int i = 0; i < BAns.size(); i++) {
                cout << BAns[i];
                if(!((i + 1) % 50) && i < BAns.size() - 1) cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}