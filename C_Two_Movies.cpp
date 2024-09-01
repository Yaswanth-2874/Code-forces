#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin>>n;

    vector<vector<int>> nums(2, vector<int>(n));
    for(int i = 0; i < n; i++)
        cin>>nums[0][i];
    for(int i = 0; i < n; i++)
        cin>>nums[1][i];
    
    int ratingsA = 0, ratingsB = 0;
    for(int i = 0; i < n; i++) {
        if(nums[0][])            
    }
    cout<<min(ratingsA, ratingsB)<<endl;
    
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
