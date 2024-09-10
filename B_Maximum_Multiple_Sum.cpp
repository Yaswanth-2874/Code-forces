#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

void solve() {
    int n;
    cin>>n;
    int sum = 0, ans = 0;

    for(int i = 2; i <= n; i++) {
        int k = n/i;
        int currentSum = (i * (k) * (k+1)) / 2;
     
        if(sum < currentSum) {
            sum = currentSum;
            ans = i;
        }
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
