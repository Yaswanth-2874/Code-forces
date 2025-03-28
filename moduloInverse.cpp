#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    int modInv(int num, int mod = 1e9 + 7) {
        return power(num, mod-2, mod);
        
    }
    int power(int x, int n, int mod = 1e9+7) {
        // only works for positive values of n
        int bit = 1;
        int current = x;
        int powValue = 1;

        for(int i = 0; i <= 62; i++) {
            if(bit & n) {
                powValue *= current;
                powValue %= mod;
            }
            current *= current;
            current %= mod;
            bit <<= 1;
        }
        return powValue;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        const int mod = 1e9 + 7;
        cout<<(modInv(n))<<endl;
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
