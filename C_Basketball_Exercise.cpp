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
    vector<vector<int>> memo;

    int findBestTeam(int index, int prevRow, vector<vector<int>>& rows) {
        if(index >= rows[0].size())
            return 0;
        if(memo[prevRow][index] != -1)
            return memo[prevRow][index];
        
        int ans = 0;

        if(prevRow != 0) {
            ans = max(ans, rows[0][index] + findBestTeam(index+1, 0, rows));
            ans = max(ans, rows[0][index] + findBestTeam(index+2, 2, rows));
        }
        if(prevRow != 1) {
            ans = max(ans, rows[1][index] + findBestTeam(index+1, 1, rows));
            ans = max(ans, rows[1][index] + findBestTeam(index+2, 2, rows));
        }

        return memo[prevRow][index] = ans;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<vector<int>> rows(2, vector<int> (n));
        memo = vector<vector<int>> (3, vector<int> (n, -1));

        input(rows[0]);
        input(rows[1]);

        int ans = findBestTeam(0, 2, rows);
        pn(ans);        
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
