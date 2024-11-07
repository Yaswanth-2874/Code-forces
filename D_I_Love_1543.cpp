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
    int findOccurances(string& st) {
        int count = 0;
        for(int i = 0; i < st.size() - 3; i++) {
            string temp = st.substr(i, 4);
            if(temp == "1543")
                count++;
        }
        return count;
    }
    int count(int row, int col, vector<string>& table, int startR, int startCol) {
        if(startR >= row || startCol >= col)
            return 0;

        string spiral = "";
        int remainingRows = row - startR;
        int remainingCols = col - startCol;

        for(int i = startR; i < col; i++)
            spiral.push_back(table[startR][i]);
        for(int i = startCol + 1; i < row; i++)
            spiral.push_back(table[i][col-1]);
        if(remainingRows > 1)
            for(int i = col - 2; i >= startCol; i--)
                spiral.push_back(table[row-1][i]);
        if(remainingCols > 1)
            for(int i = row - 2; i >= startR + 1; i--)
                spiral.push_back(table[i][startCol]);

        if(remainingCols > 1) {
            int extra = 3;
                for(int i = startR; i < min(col, startR + 3); i++) {
                    spiral.push_back(table[startR][i]);
                    extra--;
                }
            if(extra)
                if(remainingRows > 1) 
                    for(int i = startCol + 1; i < min(row, startCol + extra + 1); i++)
                        spiral.push_back(table[i][col-1]);
        }
        // cout<<spiral<<endl;
        int ans = findOccurances(spiral);
        return ans + count(row - 1, col - 1, table, startR + 1, startCol + 1);
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<string> table(n);
        for(int i = 0; i < n; i++) {
            cin >> table[i];
        }
        int ans = count(n, m, table, 0, 0);
        // int ans = count(n-1, m-1, table, 1, 1);
        pn(ans)
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
