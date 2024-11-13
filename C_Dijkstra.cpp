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
#define pii pair<int, int>
#pragma endregion

// DEMN BIDIRECTIONAL 
// DAMN IT I FORGOT TO UPDATE THE LIMITS PROPERLY

class Solution {
    int v, e;
    void minDistance(vector<vector<pii>>& graph) {
        vector<int> minDistance(v, LLONG_MAX);
        minDistance[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        vector<int> previous(v, -1);

        while(!pq.empty()) {
            auto [distance, source] = pq.top();
            pq.pop();

            if(minDistance[source] < distance)
                continue;
            
            for(auto& [destination, extraDistance] : graph[source]) {
                int currentDistance = distance + extraDistance;
                if(currentDistance < minDistance[destination]) {
                    minDistance[destination] = currentDistance;
                    pq.push({currentDistance, destination});
                    previous[destination] = source;
                }
            }
        }

        if(minDistance[v-1] == LLONG_MAX)
            pn(-1);
        vector<int> path;
        int end = v-1;

        while(end != -1) {
            path.push_back(end+1);
            end = previous[end];
        }

        reverse(all(path));
        print(path);
    }
    public:
    void solve() {
        cin >> v >> e;

        vector<vector<pii>> graph(v);
        for(int i = 0; i < e; i++) {
            int source, destination, weight;
            cin >> source >> destination >> weight;
            graph[source - 1].push_back({destination - 1, weight});
            graph[destination - 1].push_back({source - 1, weight});
        }
        minDistance(graph);
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
