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
    int balanced = 0;

    pair<int, int> findBalanced(int node, vector<vector<int>>& tree, string& colors) {
        int whiteChildren = 0, blackChildren = 0;

        for(int& destination : tree[node]) {
            auto [white, black] = findBalanced(destination, tree, colors);
            whiteChildren += white;
            blackChildren += black;
            if(white == black && white) {
                balanced++;
            }
        }

        if(colors[node] == 'W')
            whiteChildren++;
        else
            blackChildren++;
        
        return {whiteChildren, blackChildren};
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<vector<int>> tree(n);

        for(int i = 1; i < n; i++) {
            int parent;
            cin >> parent;

            tree[parent - 1].push_back(i);
        }

        string st;
        cin >> st;

        auto [white, black] = findBalanced(0, tree, st);
        if(white == black)
            balanced++;
        pn(balanced);
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
