#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<vector<int>> tree(n+1);
        vector<int> indegree(n+1);
        multiset<int> degrees;

        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
            if(indegree[u])
                degrees.erase(degrees.find(indegree[u]));
            if(indegree[v])
                degrees.erase(degrees.find(indegree[v]));

            indegree[u]++;
            indegree[v]++;

            degrees.insert(indegree[u]);
            degrees.insert(indegree[v]);
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int best = i;
            degrees.erase(degrees.find(indegree[best]));
            int val = indegree[best];

            for(int children : tree[best]) {
                degrees.erase(degrees.find(indegree[children]));
                // cout<<"Erased 1 from "<<children<<" and new count is "<<indegree[children] - 1<<endl;
                indegree[children]--;
                degrees.insert(indegree[children]);
            }

            // cout<<"Max after pop is "<<*degrees.rbegin()<<endl;

            ans = max(ans, val + *degrees.rbegin() - 1);
            for(int children : tree[best]) {
                degrees.erase(degrees.find(indegree[children]++));
                degrees.insert(indegree[children]);
            }
            degrees.insert(val);

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
