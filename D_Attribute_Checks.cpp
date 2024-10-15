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


class Solution {
    vector<vector<vector<int>>> memo;
    
    int optimal(vector<int>& nums, int index, int strength, int intel) {
        if(index >= nums.size())
            return 0;
        if(memo[index][strength][intel] != -1)
            return memo[index][strength][intel];
        if(nums[index] > 0) {
            int extra = strength >= nums[index];
            return extra + optimal(nums, index + 1, strength, intel);
        }
        if(nums[index] < 0) {
            int extra = intel >= abs(nums[index]);
            return extra + optimal(nums,index + 1, strength, intel);
        }
        int sp = optimal(nums, index + 1, strength + 1, intel);
        int ip = optimal(nums, index+ 1, strength, intel + 1);
        // cout<<max(sp, ip)<<endl;
        return max(sp, ip);
    }
    public:
    void solve() {
        
        int n, m;
        cin >> n >> m;
        memo = vector<vector<vector<int>>> (n, vector<vector<int>> (m+1, vector<int> (m+1 , -1)));
        vector<int> nums(n);
        input(nums);
        cout<<optimal(nums, 0, 0, 0)<<endl;
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

