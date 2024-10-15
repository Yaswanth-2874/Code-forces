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

// 1 2 3
// 1 3
class Solution {
    public:
    void solve() {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        input(nums);
        int sum = accumulate(all(nums), 0);
        int maxElement = *max_element(all(nums));
        sum = (sum + x - 1)/x;

        cout<<max(sum, maxElement)<<endl;
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

