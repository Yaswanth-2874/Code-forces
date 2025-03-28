#include <bits/stdc++.h>
#define int long long
using namespace std;

// I start from 0, 0 and i need to move to n-1, m-1
// total moves that i have are m - 1 + n - 1 = > n + m - 2
// Brute force TC would be 2^(n + m - 2) which would give tle
// Can use Meet in the Middle Technique
// Starting from 0, 0 -> calculate all the end points that i can reach using totalmoves/2 moves
// Now start from n-1, m-1 and calculate all the initial points by moving top or left, just brute force this

class Solution {
    map<pair<int, int>, map<int, int>> xorCounts;
    vector<vector<int>> mat;
    int totalWays = 0;
    int n, m, k;

    void firstHalf(int i, int j, int movesLeft, int xorV) {
        if(i == n || j == m)
            return;

        xorV ^=  mat[i][j];
        if(movesLeft == 0) {
            // cout<<"Current coords : "<<i<<", "<<j<<endl;
            // cout<<"Current XOR : "<<xorV<<" and "<<target<<" is the target XOR"<<endl;
            xorCounts[{i, j}][xorV]++;
            return;
        }
        firstHalf(i, j+1, movesLeft-1, xorV);
        firstHalf(i+1, j, movesLeft-1, xorV);
    }
    void lastHalf(int i, int j, int movesLeft, int xorV) {
        if(i < 0 || j < 0)
            return;
        if(movesLeft != 0)
            xorV ^= mat[i][j];
        else {
            int target = k ^ xorV;
            // cout<<"Current coords : "<<i<<", "<<j<<endl;
            // cout<<"Current XOR : "<<xorV<<" and "<<target<<" is the target XOR"<<endl;
            if(xorCounts[{i, j}].count(target)) {
                totalWays += xorCounts[{i, j}][target];
            }
            return;
        }

        lastHalf(i, j-1, movesLeft-1, xorV);
        lastHalf(i-1, j, movesLeft-1, xorV);
    }
    public:
    void solve() {
        cin >> n >> m >> k;
        mat.resize(n, vector<int> (m));

        for(int i = 0; i < n; i++) {
            for (auto& input : mat[i]) {
                cin >> input;
            }
        }
        int totalMoves = n + m - 2;


        firstHalf(0, 0, (totalMoves+1)/2, 0);
        lastHalf(n-1, m-1, (totalMoves)/2, 0);
        
        cout<<totalWays<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
