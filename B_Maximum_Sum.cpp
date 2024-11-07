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

// If i can delete from left and right side only, the best approach would be a sliding window one

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        input(nums);
        int left = 0, right = n-1;
        sort(all(nums));
        int currentSum = accumulate(all(nums), 0LL);

        while(k--) {
            currentSum -= nums[right--];
        }
        
        int maxSum = currentSum;
        while(++right < n) {
            currentSum += nums[right];
            currentSum -= nums[left++];
            currentSum -= nums[left++];
            maxSum = max(maxSum, currentSum);
        }
        cout<<maxSum<<endl;        
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

