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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    map<int, bool> respectMap;
    vector<int> ans;

    void dfs(int node, vector<vector<int>>& tree) {
        bool doesGiveRespect = respectMap[node];
        bool doesGetRespect = false;

        for(int& child : tree[node]) {
            if(respectMap[child])
                doesGetRespect = true;
            dfs(child, tree);
        }

        // cout<<"Does Node "<<node<<" give respect : "<<doesGiveRespect<<endl;
        // cout<<"Does Node "<<node<<" get respect : "<<doesGetRespect<<endl;

        if(!doesGetRespect && !doesGiveRespect)
            ans.push_back(node);
    }

    public:
    void solve() {
        int n;
        cin >> n;

        vector<vector<int>> tree(n + 1);

        int root = -1;

        for(int i = 0; i < n; i++) {
            int parent, c;
            cin >> parent >> c;
            respectMap[i+1] = !c;
            if(parent == -1) {
                root = i+1;
                continue;
            }
            tree[parent].push_back(i+1);
        }
        dfs(root, tree);
        if(ans.empty())
            pn(-1);
        sort(all(ans));
        print(ans);
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
