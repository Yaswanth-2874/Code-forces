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
        int size;
        cin>>size;

        vector<int> nums(size);
        input(nums);
        map<int, int> freq;

        int count = 0;
        for(int i = 0; i < size; i++) {
            nums[i] -= i;
            count += freq[nums[i]]++;
        }
        cout<<count<<endl;
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
