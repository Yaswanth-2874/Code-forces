#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        map<int, int> freq;
        map<int, int> count;
        map<int, int> maxCount;

        for (auto& input : v) {
            cin >> input;
            freq[input]++;
            count[input] = max(0ll, --count[input]);
            // cout<<"count of input "<<input<<

            int otherNumber = input*x;
            count[otherNumber]++;
            // cout<<"oTHER NUMBER is "<<otherNumber<<" and count is "<<count[otherNumber]<<endl;
            maxCount[otherNumber] = max(count[otherNumber], maxCount[otherNumber]);
        }
        int ans = 0;

        for(auto& [num, f] : freq) {
            if(x == 1) {
                ans = max(ans, f);
                continue;
            }
           
            int maxi = maxCount[num];
            // cout<<otherNumber<<" for "<<num<<" and freq is "<<maxi<<endl;
           
            ans = max(ans, f + maxi);
        }
        /* Print number*/ {
            cout<<ans<<endl;
            return;
        }

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
