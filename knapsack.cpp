#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    int maxWeight;

    int maxProfit(vector<int>& weights, vector<int>& profits, int index, int currentWeight) {
        // BaseCase
        if(currentWeight > maxWeight)
            return 0;

        int pick = profits[index] + maxProfit(weights, profits, index + 1, currentWeight + weights[index]);
        int dontPick = maxProfit(weights, profits, index + 1, currentWeight);

        return max(pick, dontPick);
    }
    public:
    void solve() {
        vector<int> weights = {10, 18, 5};
        vector<int> profits = {25, 15, 10};
        maxWeight = 20;

        cout<<maxProfit(weights, profits, 0, 0);
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

