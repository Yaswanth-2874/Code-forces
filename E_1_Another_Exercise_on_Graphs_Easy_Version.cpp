#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<vector<pair<int, int>>> graph;
    map<pair<int, int>, vector<int>> mv; 

    void dfs(int node, int currDistance, int source) {

        for(auto& [dest, weight] : graph[node]) {
            // if(mv.find({source, dest}) == mv.end()) 
            // mv[{source, dest}].push_back(currDistance + weight); 
            dfs(dest, currDistance + weight, source);
        }
    }
    public:
    void solve() {

        int n, m , k;
        cin >> n >> m >> k;

        graph.resize(n+1);
        
        for(int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
            // cout<<graph[a].size()<<endl;
        }
        
        
        for(int i = 1; i <= n; i++) {
            dfs(i, 0, i);
        }
        
        // for(auto& [_, vec] : mv) {
        //     sort(begin(vec), end(vec), greater<int> ());
        // }

        cout<<"REa";
        while(k--) {
            int a, b, q;
            cin >> a >> b >> q;
            q--;
            // cout<<mv[{a, b}][q]<<" ";
        }
        // cout<<endl;
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
