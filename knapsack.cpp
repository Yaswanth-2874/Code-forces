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
    vector<vector<int>> memo;

    int maxProfit(vector<int>& weights, vector<int>& profits, int index, int currentWeight) {
        // BaseCase
        if(index >= weights.size())
            return 0;
        if(memo[index][currentWeight] != -1)
            return memo[index][currentWeight];

        int dontPick = maxProfit(weights, profits, index + 1, currentWeight);
        int pick = 0;
        if(currentWeight + weights[index] <= maxWeight)
            pick = maxProfit(weights, profits, index+1, currentWeight + weights[index]) + profits[index];

        return memo[index][currentWeight] = max(pick, dontPick);
    }
    public:
    void solve() {
        int size;
        cin >> size >> maxWeight;

        vector<int> weights(size);
        vector<int> profits(size);

        input(weights);
        input(profits);

        memo = vector<vector<int>> (weights.size(), vector<int> (maxWeight, -1));

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

