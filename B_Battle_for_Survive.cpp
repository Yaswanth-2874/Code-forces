#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);

        if(nums.size() == 2) {
            cout<<nums[1] - nums[0]<<endl;
            return;
        }
        
        int sum = 0;
        for(int i = 0; i < n - 2; i++)
            sum += nums[i];
        nums[n-2] -= sum;
        cout<<nums[n-1] - nums[n-2]<<endl;



    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}

