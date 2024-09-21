#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

class Solution {
    map<pair<int, int>, pair<int, int>> weights;

    int calculateCost(int parent, int current, vector<vector<int>>& graph, bool cycleStarted = false) {
        // cout<<current<<" ";
        if(cycleStarted && current == 0) {
            // auto [weight, connected] = weights[{parent, current}];
            // if(!connected)
            //     return weight;
            return 0;
        }

        for(int neighbour : graph[current]) {
            if(neighbour == parent)
                continue;
            auto [weight, connected] = weights[{current, neighbour}];
            if(!connected)
                return weight + calculateCost(current, neighbour, graph, true);
            return calculateCost(current, neighbour, graph, true);
        }
        return 0;
    }
public:
    void solve() {
        int nodes;
        cin>>nodes;
        vector<vector<int>> graph(nodes);

        int totalWeight = 0;

        for(int i = 0; i < nodes; i++) {
            int parent, child, weight;
            cin>>parent>>child>>weight;
            parent--;
            child--;

            totalWeight += weight;

            weights[{parent, child}] = {weight, 1};
            weights[{child, parent}] = {weight, 0};
            graph[parent].push_back(child);
            graph[child].push_back(parent);
        }

        int cost1 = calculateCost(graph[0][0], 0, graph);
        int cost2 = totalWeight - cost1;
        // cout<<cost1<<" "<<cost2<<" "<<totalWeight<<endl;
        
        cout<<min(cost1, cost2)<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution *ob = new Solution();
        ob->solve();
    }
    return 0;
}
