#include <bits/stdc++.h>
#define int long long
using namespace std;

// NOT CONFIDENT

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto& input : a) {
            cin >> input;
        }
        for (auto& input : b) {
            cin >> input;
        }

        vector<int> dp(n, 0);

        dp[n-1] = b[n-1] >= 1 ? 0 : 1;

        for(int i = n-2; i >= 0; i--) {
            int minRequiredForNext = dp[i+1];
            int choice1 = minRequiredForNext + 1; // this works for sure, now what's alt??
            // if i can gain rating here, then try to gain all of it
            // can only gain rating if curr <= a[i]
            if(b[i]) {
                int choice2 = max(0ll, choice1 - b[i]);
                if(choice2 <= a[i]) {
                    choice1 = choice2;
                }
            } 
  
            dp[i] = max(choice1, 0ll);
        }
        int ans1 = dp[0];
        // i must leave 0th index with atleast dp[0];
        if(b[0]) {
            int ans2 = max(0ll, ans1 - b[0]);
            // cout<<"L : "<<ans2<<endl;
            if(ans2 <= a[0])
                ans1 = ans2;
        } else {
            ans1 += 1;
        }
        
        // /* Print array*/ {
        //     for(auto& val : dp) {
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }

        cout<<dp[0]<<endl;

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
