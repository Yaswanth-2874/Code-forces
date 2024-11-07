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

// Jinxed it
// I USED ACCUMULATE(ALL(NUMS), 0) instead of 0LL
// IT OVERFLOWS

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);

        int totalSum = accumulate(all(nums), 0);
        int currentSum = 0, maxSum = 0;

        int left = 0;
        int right = 0;

        // I need to find maxSum excluding the last element
        while(right < (n - 1)) {
            currentSum += nums[right++];
            if(currentSum == 0) {
                left = right;
                continue;
            }
            while(currentSum < 0) {
                currentSum -= nums[left++];
            }

            maxSum = max(maxSum, currentSum);
        }
        if(left == 0)
            currentSum -= nums[left];
        currentSum += nums[right];
        int optimalSum = max(currentSum, maxSum);
        // cout<<totalSum<<" "<<optimalSum<<endl;
        if(totalSum > optimalSum)
            yes;
        no;
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

