#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
  
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    if(nums[1] - nums[0] == 1 || nums.size() >= 3)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
