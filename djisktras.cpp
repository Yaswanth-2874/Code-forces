#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define pii pair<int, int>


class Solution {
    vector<int> dijsktra(vector<vector<pii>>& graph) {
        vector<int> distances(graph.size(), LLONG_MAX);
        priority_queue<minHeap(pii)> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [distance, source] = pq.top();
            pq.pop();

            if(distance > distances[source])
                continue;

            for(auto& [pathDistance , destination] : graph[source]) {
                if(distance + pathDistance < distances[destination]) {
                    pq.push({distance + pathDistance, destination});
                    distances[destination] = distance + pathDistance;
                }
            }          
        }

        return distances;
    }
    public:
    void solve() {
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

