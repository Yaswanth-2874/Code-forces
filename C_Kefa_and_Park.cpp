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
    int count, k;
    vector<vector<int>> tree;
    void dfs(int node, int current, vector<int>& catsPresent, int parent, bool condition) {
        if(catsPresent[node] == 1) {
            current++;
        } else {
            current = 0;
        }
        if(current > k)
            condition = true;
        // cout<<"Cats present till "<<node<<" is "<<current<<endl;

        if(tree[node].size() == 1 && parent != -1) {
            if(!condition)
                count++;
            return;
        }
        for(int& children : tree[node]) {
            if(parent == children)
                continue;
            
            dfs(children, current, catsPresent, node, condition);
        }
    }
    public:
    void solve() {
        int n;
        cin >> n >> k;
        count = 0;
        array(int, catsPresent, n);
        tree.resize(n);

        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--;v--;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(0, 0, catsPresent, -1, false);
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
