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

// I AM HAPPY WITH MY BINARY SEARCH APPROACH BUT TOOK TO LONG TO FIX ITS ISSUES
// NOW I THOUGHT OF ANOTHER MORE EFFICIENT APPROACH
// CREATE A SLIDING WINDOW WITH SUM = TARGET SUM AND FIND MAX LENGTH OF IT

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        input(nums);

        int left = 0, currentSum = 0;
        int totalSum = accumulate(all(nums), 0);
        if(totalSum < k)
            pn(-1);
        if(totalSum == k)
            pn(0);
        int maxWindowSize = 0;

        for(int right = 0; right < n; right++) {
            currentSum += nums[right];
            while(currentSum > k) {
                currentSum -= nums[left++];
            }
            int currentWindowSize = right - left + 1;
            maxWindowSize = max(maxWindowSize, currentWindowSize);
        }
        cout<<n - maxWindowSize<<endl;
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

