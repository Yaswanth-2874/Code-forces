#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
    bool isNotCycle;
    void dfs(int node, bool& cyclePresent, int parent) {
        if(visited[node]) {
            cyclePresent = !isNotCycle;
            return;
        }
        visited[node] = true;
        if(graph[node].size() > 2)
            isNotCycle = true;
        for(int& neighbour : graph[node]) {
            if(neighbour == parent)
                continue;
            dfs(neighbour, cyclePresent, node);
        }
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        graph.resize(n);
        visited.resize(n);

        while(m--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int count = 0;

        for(int i = 0; i < n; i++) {
            bool cyclePresent = false;
            isNotCycle = false;
            if(visited[i])
                continue;
            dfs(i, cyclePresent, -1);
            count += cyclePresent;
        }
        pn(count);
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
