#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

// 1 2 1 3
// 1 2 1 3
// 1 2 3
// 1 2
// 1

class Solution {
    public:
    void solve() {
        int n;
        cin>>n;
        vector<int> nums(n);
        input(nums);
        set<int> uniques(full(nums));

        if(uniques.size() >= 3)
            cout<<n<<endl;
        else
            cout<<n/2 + 1<<endl;
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
