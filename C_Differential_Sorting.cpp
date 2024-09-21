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

        if(nums[n - 2] > nums[n - 1]) {
            cout<<-1<<endl;
            return;
        }

        if(is_sorted(full(nums))) {
            cout<<0<<endl;
            return;
        }

        int diff = nums[n-2] - nums[n-1];
        if(diff <= nums[n-2]) {
            cout<<n-2<<endl;
            for(int i = 1; i <= n-2; i++) {
                cout<<i<<" "<<n-1<<" "<<n<<endl;
            }
            return;
        }
        cout<<-1<<endl;
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
