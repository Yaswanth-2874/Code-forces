#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);
        int ans1 = 0, max1 = 0, ans2 = 0, max2 = 0;
        for(int i = 0; i < n; i+=2) {
            max1 = max(max1, nums[i]);
            ans1++;
        }
        for(int i = 1; i < n; i += 2) {
            max2 = max(max2, nums[i]);
            ans2++;
        }
        int ans = max(ans1+max1, ans2+max2);
        cout<<ans<<endl;
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

