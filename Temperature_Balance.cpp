#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        
        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        int ans = 0;
        int curr = v[0];

        for(int i = 1; i < n; i++) {
            ans += abs(curr);
            curr += v[i];
        }
        cout<<ans<<endl;
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
