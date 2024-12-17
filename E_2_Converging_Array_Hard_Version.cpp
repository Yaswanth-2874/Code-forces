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
    class DisjointSet {
        vector<int> parent, size;
        public:
        DisjointSet(int n) {
            size.resize(n, 1);
            for(int i = 0; i < n; i++)
                parent.push_back(i);
        }
        int findParent(int node) {
            if(parent[node] == node)
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
    };
    vector<pair<int, int>> directions;
    int m, n, rooms;
    int address(int i, int j) {
        return n*i + j;
    }
    void mergeNeighbours(int  x, int y, vector<string>& board, DisjointSet& ds) {
        int base = address(x, y);
        for(auto& [xInc, yInc] : directions) {
            int newX = x + xInc;
            int newY = y + yInc;

            if(newX >= m || newY >= n || newX < 0 || newY < 0 || board[newX][newY] == '#')
                continue;
            int current = address(newX, newY);
            if(ds.unionMerge(current, base))
                rooms--;
        }
    }
    public:
    void solve() {
        rooms = 0;
        cin >> m >> n;
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        array(string, board, m);
        DisjointSet ds(m*n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    rooms++;
                    mergeNeighbours(i, j, board, ds);
                }
            }
        }
        pn(rooms)           
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
