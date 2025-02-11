#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int l, r;
        cin >> l >> r;
        int bit = 1<<30;
        int diffIndex = -1;
        int a = 0;

        for(int i = 30; i >= 0; i--) {
            int lSet = bit & l;
            int rSet = bit & r;
    
            if(rSet) {
                a |= bit;
            }
            
            if(rSet != lSet) {
                diffIndex = i;
                break;
            }
            
            bit >>= 1;
        }
        // /* Print number*/ {
        //     cout<<a<<endl;
        //     return;
        // }
        
        int b, c;
        if(a + 1 <= r)
            b = a+1;
        else
            b = a-1;
        c = l;
        bit = 1 << 30;

        for(int i = 30; i >= 0; i--) {
            // cout<<bit<<endl;
            int bitA = (a & bit);
            int bitB = (b & bit);

            // cout<<bitA<<" and "<<a<<endl;

            if(!bitA && !bitB) {
                // cout<<"I can change bit "<<i<<endl;
                if((c | bit) <= r)
                    c |= bit;
            }

            bit >>= 1;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
        
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
