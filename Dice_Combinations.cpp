#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
class Solution {
    public:
    void solve() {
        int target;
        cin >> target;

        vector<int> dp(target + 1);
        dp[1] = dp[0] = 1;
        for(int i = 2; i <= target; i++) {
            for(int j = i-1; j >= 0 && j >= i-6; j--) {
                dp[i] += dp[j];
                dp[i] %= mod;
            } 
        }

        cout<<dp[target];
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
