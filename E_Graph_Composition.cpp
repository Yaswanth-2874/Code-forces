#include <bits/stdc++.h>
#define int long long
using namespace std;

// Can only remove or add edges in F
// Can i count number of removals first and then additions? Viceversa??

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
        int n, m1, m2;
        cin >> n >> m1 >> m2;

        DisjointSet F(n+1), G(n+1);
        vector<pair<int, int>> fEdges;

        for(int i = 0; i < m1; i++) {
            int n, m;
            cin >> n >> m;

            fEdges.push_back({n, m});
        }

        for(int i = 0; i < m2; i++) {
            int n, m;
            cin >> n >> m;

            G.unionMerge(n, m);
        }
        int moves = 0;

        for(auto& [u, v] : fEdges) {
            int uParent = G.findParent(u);
            int vParent = G.findParent(v);

            // Delete the edge if they are not connected
            if(uParent != vParent) {
                moves++;
            } else {
                F.unionMerge(u, v);
            }

        }

        // Now add remainining edges

        int gParents = 0, fParents = 0;
        for(int i = 1; i <= n; i++) {
            if(G.findParent(i) == i) {
                gParents++;
            }
            if(F.findParent(i) == i) {
                fParents++;
            }
        }

        cout<<moves + fParents - gParents<<endl;

    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
