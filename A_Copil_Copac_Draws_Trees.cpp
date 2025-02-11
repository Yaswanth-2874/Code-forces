#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<vector<int>> tree;
    vector<int> firstOccurance, ans;
    vector<bool> visited;
    map<pair<int, int>, int> occ;
    void dfs(int node, int val) {
        if(visited[node])
            return;
        // cout<<"Visiting "<<node<<" and ans for this is "<<val<<endl;

        visited[node] = true;
        ans[node] = val;

        for(auto& child : tree[node]) {
            firstOccurance[child] = occ[{node, child}];
            // cout<<"Occurance of parent "<<node<<" is "<<firstOccurance[node]<<" and child "<<child<<" is "<<firstOccurance[child]<<endl;
            if(firstOccurance[child] < firstOccurance[node]) {
                dfs(child, val+1);
            } else {
                dfs(child, val);
            }
        }

    }
    public:
    void solve() {
        int n;
        cin >> n;

        tree.resize(n+1);
        firstOccurance.resize(n+1, -1);
        ans.resize(n+1, 1);
        visited.resize(n+1, false);

        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
            if(occ.find({u, v}) == occ.end())
                occ[{u, v}] = occ[{v, u}] = i;
            if((u == 1 || v == 1) && firstOccurance[1] == -1) {
                firstOccurance[1] = i;
            }
        }
        dfs(1, 1);

        cout<<*max_element(begin(ans), end(ans))<<endl;
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
