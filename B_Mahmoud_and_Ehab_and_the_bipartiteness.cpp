#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    void dfs(int color, vector<vector<int>>& graph, vector<int>& colors, int node) {
        if(colors[node] != -1)
            return;
        
        colors[node] = color;
        for(auto& child : graph[node]) {
            dfs(!color, graph, colors, child);
        }
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<vector<int>> graph(n+1);

        for(int i = 0; i < n-1; i++) {
            int nodeA, nodeB;
            cin >> nodeA >> nodeB;

            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }

        vector<int> colors(n+1, -1);

        dfs(1, graph, colors, 1);
        // print(colors)
        
        int positiveColors = 0;
        for(int& color : colors)
            positiveColors += color == 1;
        
        int zeroColors = n - positiveColors;
        int extraEdges = positiveColors*zeroColors - n + 1;
        // cout<<positiveColors<<" "<<zeroColors<<endl;
        pn(extraEdges)
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
