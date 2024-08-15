#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<ll> nums(n);
    vector<ll> sums(n, 0);
    string direction;
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
        if(i == 0) {
            sums[i] = nums[i];
        }
        else {
            sums[i] = sums[i - 1] + nums[i];
        }
    }
    // cout<<sums[n-1]<<endl;
    cin>>direction;
    ll left = 0, right = n-1;
    ll ans = 0;
    while(left < right) {
        while(left < n && direction[left] != 'L')
            left++;
        while(right >= 0 && direction[right] != 'R')
            right--;
        if(left > right)
            break;
        ll leftSum = 0;
        if(left != 0)
            leftSum = sums[left - 1];
        ans += sums[right] - leftSum;
        left++;
        right--;
    }
    cout<<ans<<endl;


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
