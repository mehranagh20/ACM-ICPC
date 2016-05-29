#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    while (cin >> h >> w && h != 0 && w != 0) {
        vector<bool> alreadyConsidered(h + 1, false);
        int currHei, ans = 0;
        while(w--)
        {
            cin >> currHei;
            int tmp = currHei;
            if(!alreadyConsidered[++currHei])
            {
                while(currHei <= h && !alreadyConsidered[currHei]) {
                    alreadyConsidered[currHei++] = true;
                    ans++;
                }
            }
            while(alreadyConsidered[tmp] && tmp > 0)
                alreadyConsidered[tmp--] = false;
        }
        cout << ans << endl;
    }

    return 0;
}