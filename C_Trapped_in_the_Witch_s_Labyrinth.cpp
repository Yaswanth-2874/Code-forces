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
    class DisjointSet {
        vector<int> parent, size;
        public:
        vector<bool> useless;
        DisjointSet(int n) {
            size.resize(n, 1);
            useless.resize(n, false);
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
            if(useless[parentA] || useless[parentB]) {
                useless[parentA] = useless[parentB] = true;
            }

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
        void makeParentUseless(int node) {
            int parent = findParent(node);
            useless[parent] = true;
        }
        int findSize(int nodeA) {
            int parentA = findParent(nodeA);
            return size[parentA];
        }
        bool isUseless(int nodeA) {
            int parentA = findParent(nodeA);
            return useless[parentA];
        }
    };
    vector<pair<int, int>> directions;
    int n, m;
    int address(int row, int col) {
        return row* m + col;
    }

    void merge(int i, int j, vector<string>& grid, DisjointSet& ds) {
        int base = address(i, j);

        if(grid[i][j] == 'U') {
            if(i-1 >= 0) {
                int curr = address(i-1, j);
                ds.unionMerge(base, curr);
            } else {
                ds.makeParentUseless(base);
            }
        }
        if(grid[i][j] == 'D') {
            if(i+1 < n) {
                int curr = address(i+1, j);
                ds.unionMerge(base, curr);
            } else {
                ds.makeParentUseless(base);
            }
        }
        if(grid[i][j] == 'L') {
            if(j-1 >= 0) {
                int curr = address(i, j-1);
                ds.unionMerge(base, curr);
            } else {
                ds.makeParentUseless(base);
            }
        }
        if(grid[i][j] == 'R') {
            if(j+1 < m) {
                int curr = address(i, j+1);
                ds.unionMerge(base, curr);
            } else {
                ds.makeParentUseless(base);
            }
        }
    }

    int check(int i, int j, DisjointSet& ds, vector<string>& grid) {
        int ans = 0;
        int add = address(i, j);

        for(auto& [x, y] : directions) {
            int newX = x+i;
            int newY = y+j;

            if(newX >= n || newY >= m || newY < 0 || newX < 0)
                continue;
            
            if(grid[newX][newY] == '?')
                return 1;
            
            int newAdd = address(newX, newY);
            if(ds.isUseless(newAdd) == false)
                return 1;
        }
        return 0;
    }

    public:
    void solve() {
        cin >> n >> m;
        vector<string> grid(n);
        directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        DisjointSet ds(m*n);

        for(int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != '?')
                    merge(i, j, grid, ds);
            }
        }
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '?') {
                    ans += check(i, j, ds, grid);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int add = address(i, j);
                // cout<<ds.isUseless(add)<<" ";
                if(grid[i][j] != '?') {
                if(ds.isUseless(add) == false)
                    ans++;
                }
            }
            // cout<<endl;
        }
        pn(ans);
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
