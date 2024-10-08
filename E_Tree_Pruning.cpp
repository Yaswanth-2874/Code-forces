#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    int n;
    void bfs(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> endLevels(n, 0);
        vector<int> childrenCount(n);
        q.push(0);
        int level = 0;
        int remaining = n;

        while(!q.empty()) {
            int size = q.size();
            childrenCount[level] = size;
            while(size--) {
                int t = q.front();
                q.pop();
                bool ended = true;
                for(int child : graph[t]) {
                    q.push(child);
                    ended = false;
                }
                if(ended)
                    endLevels[level]++;
            }
            level++;
        }
        int ans = n;
        int removedNodes = 0;
        int totalNodes = n, currentNodes = 0;
        for(int end : endLevels)
            cout<<end<<" ";
        cout<<endl;

        for(int i = 0; i < n; i++) {
            currentNodes += childrenCount[i];
             cout<<"Level : "<<i<<" , Nodes above : "<<(n - currentNodes)<<" , eliminated nodes : "<<removedNodes<<endl;
            ans = min((n-currentNodes) + removedNodes, ans);
            removedNodes += endLevels[i];
        }

        cout<<ans<<endl;
    }
    public:
    void solve() {
        cin >> n;
        vector<vector<int>> graph(n);
        for(int i = 0;i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
        }
        bfs(graph);
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

