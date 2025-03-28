#include <bits/stdc++.h>
#define int long long
using namespace std;

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
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }
        DisjointSet ds(n);
        int ans = (n * (n - 1)) / 2;
      
        for(int i = 0; i <= 30; i++) {
            int bit = 1 << i;
            vector<int> matches;

            for(int j = 0; j < n; j++) {
                if(bit & v[j])
                    matches.push_back(j);
            }

            if(matches.size() > 1) {
                int best = matches[0];
                for(int j = 1; j < matches.size(); j++)
                    ds.unionMerge(best, matches[j]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(ds.findParent(i) == i) {
                int size = ds.findSize(i);
                cout<<size<<" for index "<<i<<endl;
                ans += (size * (size - 1)) / 2;
            }
        }
        /* Print number*/ {
            cout<<ans<<endl;
            return;
        }
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
