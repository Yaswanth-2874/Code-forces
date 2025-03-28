#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int l, r;
        cin >> l >> r;

        for(int i = l; i <= r; i++) {
            int sum = 0;
            int product = 1, cpy = i;
            while(cpy) {
                int digit = cpy % 10;
                product *= digit;
                sum += digit;
                cpy /= 10;
            }
            if(product && product % sum == 0)
                cout<<i<<" ";
        }
        cout<<endl;

        
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
