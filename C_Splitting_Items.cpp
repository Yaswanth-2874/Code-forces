#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n, k;
    cin>>n>>k;

    vector<ll> costs(n);
    for(int i = 0; i < n; i++) {
        cin>>costs[i];
    }
    sort(costs.begin(), costs.end(), greater<int>());
    bool aliceTurn = true;
    ll aliceScore = 0, bobScore = 0;

    for(int i = 0; i < n; i ++) {
        if(aliceTurn)
            aliceScore += costs[i];
        else {
            if(costs[i-1] - costs[i] <= k) {
                k -= (costs[i-1] - costs[i]);
                costs[i] = costs[i-1];
            }
            else {
                costs[i] += k;
                k = 0;
            }
            bobScore += costs[i];
        }
        aliceTurn = !aliceTurn;
    }
    cout<<aliceScore - bobScore<<endl;

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
