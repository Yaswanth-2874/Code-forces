#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
  
        for(int i = 1; i <= n; i++) {
            int j = i;

            while(j) {
                int mod = j % 10;
                j /= 10;
                if(mod == 0) 
                    continue;
                dp[i] = min(dp[i], 1 + dp[i - mod]);
            }
        }

        cout<<dp[n];
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
