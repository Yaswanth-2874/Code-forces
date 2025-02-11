#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<vector<int>> tree(n+1);
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int ans = 0;
        
        
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
