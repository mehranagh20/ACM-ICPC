#include <iostream>
#include <string>

using namespace std;

int main() {
    string tracks;
    int n;
    cin >> n;
    while (getchar() != '\n');
    while(n--)
    {
        getline(cin, tracks);
        int mm = 0, ff = 0, mf = 0;
        for(int i = 0; i < tracks.size(); i++)
        {
            if(isalpha(tracks[i]))
            {
                if(tracks[i] == 'M')
                {
                    if(tracks[++i] == 'M')
                        mm++;
                    else
                        mf++;
                }
                else
                {
                    if(tracks[++i] == 'F')
                        ff++;
                    else
                        mf++;
                }
                i++;
            }
        }
        if(mf == 1 || mm != ff)
            cout << "NO LOOP" << endl;
        else
            cout << "LOOP" << endl;
    }

    return 0;
}