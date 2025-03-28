#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, coins;
        cin >> n >> coins;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        vector<int> minCoins(coins + 1, INT_MAX);
        minCoins[0] = 0;

        for(int i = 1; i <= coins; i++) {
            for(int coin : v) {
               int diff = i - coin;
               if(diff >= 0)
                    minCoins[i] = min(minCoins[i], 1 + minCoins[diff]);
            }
        }

        cout<<(minCoins[coins] == INT_MAX ? - 1 : minCoins[coins]);
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
