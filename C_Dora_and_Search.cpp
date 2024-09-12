#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

void solve() {
    int size;
    cin>>size;
    vector<int> nums(size);
    input(nums);

    int currMin = 1, currMax = size;
    int left = 0, right = size - 1;

    while(left < right) {
        if(nums[left] == currMin || nums[left] == currMax) {
            currMin += nums[left] == currMin;
            currMax -= nums[left++] == currMax;
        } else if(nums[right] == currMax || nums[right] == currMin) {
            currMin += nums[right] == currMin;
            currMax -= nums[right--] == currMax;
        } else {
            cout<<left+1<<" "<<right+1<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
