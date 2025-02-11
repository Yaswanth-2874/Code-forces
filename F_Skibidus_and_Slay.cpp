#include <bits/stdc++.h>
#define int long long
using namespace std;

//tle , optimise it
// would never use unordered map in a live contest lol but this should not matter ig
class Solution {
    unordered_map<int, unordered_map<int, int>> neighbours;

    bool bfs(vector<vector<int>>& tree, int node, vector<int>& v, string& res) {
        int target = v[node-1];
        if(res[target-1] == '1')
            return true;

        for(auto& child : tree[node]) {
            if(v[child-1] == target) {
                res[target-1] = '1'; 
                if(node == 2)
                return true;
            }
            if(neighbours[child][target] > 1) {
                res[target-1] = '1'; 
                return true;
            }
        }
        return false;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        string res(n, '0');
        for (auto& input : v) {
            cin >> input;
        }

        vector<vector<int>> tree(n+1);
        
        
        for(int i = 0; i < n-1; i++) {
            int u, va;
            cin >> u >> va;
            tree[u].push_back(va);
            tree[va].push_back(u);
            neighbours[u][v[va-1]]++;
            neighbours[va][v[u-1]]++;
        }

        // going to do a bfs of depth 2, amazing approach!! 
        for(int start = 1; start <= n; start++) {
            bfs(tree, start, v, res);
        }

        cout<<res<<endl;
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
