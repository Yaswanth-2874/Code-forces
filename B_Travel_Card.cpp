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

// Find the first index where it is optimal to buy the 50$ and 120$ ticket and pay the remaining balance here
class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        array(int, v, n);
        vector<int> dp(n);
        dp[0] = 20;
        cout<<20<<endl;
        for(int i = 1; i < n; i++) {
            int buyTicket = 20 + dp[i-1];
            int index1 = upper_bound(all(v), v[i] - 90) - v.begin();
            int index2 = upper_bound(all(v), v[i] - 1440) - v.begin();
            int cost1 = index1 ? dp[index1 - 1] + 50 : 50;
            int cost2 = index2 ? dp[index2 - 1] + 120: 120;
            // cout<<cost1<<" "<<cost2<<" "<<dp[i-1]<<endl;
            dp[i] = min({buyTicket, cost1, cost2});
            cout<<dp[i] - dp[i-1]<<endl;
        }
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
