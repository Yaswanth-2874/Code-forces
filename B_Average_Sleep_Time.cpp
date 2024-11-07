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

// I am worried about the precision

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        vector<int> nums(n);
        input(nums);

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int totalSum = sum;
        int left = 0, right = k;
        while(right < n) {
            sum -= nums[left++];
            sum += nums[right++];
            totalSum += sum;
        }
        
        double ans = (double)totalSum / (n - k + 1);
        cout << fixed << setprecision(6) << ans << endl;
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

