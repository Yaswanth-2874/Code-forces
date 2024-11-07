#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

vector<pair<int, int>> directions;
// This is 3d MEMO but 2 dimensions are small (2 * 2 * n)
// hope it gets accepted

class Solution {
    int n;
    vector<vector<vector<int>>> memo;
    bool canReachEnd(int x, int y, int freeToMove, vector<string>& rows) {
        cout<<"Moved into "<<x<<" "<<y<<endl;
        if(x >= 2 || y >= n || x < 0 || y < 0 || rows[x][y] == 'V')
            return false;
        if(x == 1 && y == n-1)
            return true;
        if(memo[x][y][freeToMove] != -1)
            return memo[x][y][freeToMove];
        
        rows[x][y] == 'V';

        if(freeToMove == 0) {
            if(rows[x][y] == '<')
                return memo[x][y][freeToMove] = canReachEnd(x, y-1, 1, rows);
            return memo[x][y][freeToMove] = canReachEnd(x, y+1, 1, rows);
        }
        for(auto& [xInc, yInc] : directions) {
            if(canReachEnd(x + xInc, y + yInc, 0, rows))
                return memo[x][y][freeToMove] = true;
        }
        return memo[x][y][freeToMove] = false;
    }
    public:
    void solve() {
        cin >> n;
        vector<string> rows(2);
        cin >> rows[0];
        cin >> rows[1];
        
        memo = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(2, -1)));

        if(canReachEnd(0, 0, 1, rows))
            yes;
        no;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

