//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

llu gcd(llu n1, llu n2)
{
    return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

int main() {
    llu p, q;
    vector<llu> nums(49999), eq(49999);
    for(llu i = 0; i < 49999; i++) {
        llu tmp = (i + 1) * (i + 2);
        nums[i] = (i + 1) * (i + 2);
        eq[i] = i + 2;
    }
   // cout << nums[0] << endl;
    sort(nums.begin(), nums.end());
    //cout << binary_search(nums.begin(), nums.end(), 2499850002) << endl << binary_search(nums.begin(), nums.end(), 2499950000);
    while(cin >> p >> q && (p || q)) {
        if(!p) {
            printf("0 2\n");
            continue;
        }
        llu g = gcd(q, p); p /= g; q /= g;
        auto it1 = nums.end(), it2 = nums.end();
        llu ans1, ans2;
        bool found = false;
        for(int j = 0; j < nums.size(); j++) {
            llu el = nums[j];
            if(!(el % q)) {
                int i = el / q;
                llu tmp = sqrt(p * i);
                if(tmp * (tmp + 1) == p * i) {
                    ans1 = tmp + 1;
                    ans2 = eq[j] - ans1;
                    found = true;
                    break;
                }
            }
        }
        if(found) cout << ans1 << " " << ans2 << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}