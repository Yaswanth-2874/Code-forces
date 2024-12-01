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

// very easy disjoint set question

class Solution {
    class DisjointSet {
        vector<int> parent, size;
        public:
        DisjointSet(int n) {
            size.resize(n, 1);
            for(int i = 0; i < n; i++)
                parent.push_back(i);
        }
        int findParent(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }
        bool unionMerge(int nodeA, int nodeB) {
            int parentA = findParent(nodeA);
            int parentB = findParent(nodeB);

            if(parentA == parentB)
                return false;
            
            if(size[parentA] >= size[parentB]) {
                size[parentA] += size[parentB];
                parent[parentB] = parentA;
            } else {
                size[parentB] += size[parentA];
                parent[parentA] = parentB;
            }

            return true;
        }
        int findSize(int nodeA) {
            int parentA = findParent(nodeA);
            return size[parentA];
        }

    };
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        DisjointSet ds(n+1);
        for(int i = 0; i < m; i++) {
            int groupSize;
            cin >> groupSize;

            if(groupSize == 0)
                continue;
            
            int firstMember;
            cin >> firstMember;

            for(int j = 1; j < groupSize; j++) {
                int currentMember;
                cin >> currentMember;
                ds.unionMerge(firstMember, currentMember);
            }
        }

        for(int i = 1; i <= n; i++) {
            cout<<ds.findSize(i)<<" ";
        }
        cout<<endl;

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
