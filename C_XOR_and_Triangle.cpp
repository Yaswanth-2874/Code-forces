#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int x;
        cin >> x;

        // y should be less than x
        // x ^ y , x, y should be a triangle

        if(__builtin_popcount(x) == 1 || __builtin_popcount(x+1) == 1)
            /* Print number*/ {
                cout<<-1<<endl;
                return;
            }
        
            
        // for(int y = 0; y < x; y++) {
        //     int xorV = x ^ y;
        //     if(x + y > xorV && xorV + x > y && xorV + y > x) {
        //         cout<<y<<" for "<<x<<endl;
        //         return;
        //     }
        // }
        // cout<<-1<<endl;

        for(int i = 1; i < 31; i++) {
            int bit = 1ll << i;
            int y = bit + 1;
            int xorV = x ^ y;
            if(x + y > xorV && xorV + x > y && xorV + y > x)
            /* Print number*/ {
                cout<<y<<endl;
                return;
            }
        }

        // cout<<"End for "<<x<<endl;
        
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
