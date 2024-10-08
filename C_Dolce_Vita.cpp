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

// Forgot to write one equal to sign and i was not able to spot it for 40 min , logic was working on my mind :(
// BRUH I WROTE <= instead of <, whats wrong with me :(
// BE BETTER

class Solution {
    int x;
    int howManyCanIBuy(int cost, int money, int previousItems ) {
        int minDay = 0, maxDay = 1e9;
        // For any day, if i started with x coins on day 1, then on nth day i start with x - ((index - 1) * n) coins
        // My todays price would be (day - 1) + currentPrice
        while(minDay <= maxDay) {
            int midDay = minDay + (maxDay - minDay) / 2;
            int currentCost = cost + midDay - 1;
            
            int previousItemCost = previousItems * (midDay - 1);
            int remainingMoney = money - previousItemCost - currentCost;
            // cout<<"DAY : "<<midDay<<" , remaining Amount : "<<remainingMoney<<endl;
            if(remainingMoney >= 0) 
                minDay = midDay + 1;
            else
                maxDay = midDay - 1;
        }
        // cout<<"BOUGHT "<<maxDay<<" copies"<<endl;
        return maxDay;
    }
    public:
    void solve() {
        int n;
        cin >> n >> x;
        vector<int> nums(n);
        input(nums);
        sort(all(nums));

        int totalPurchases = 0;

        for(int i = 0; i < nums.size(); i++) {
            int purchases = howManyCanIBuy(nums[i], x, i);
            if(purchases <= 0)
                break;
            totalPurchases += purchases;
            x -= nums[i];//Assume that i purchased the currentProduct;
        }
        cout<<totalPurchases<<endl;
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