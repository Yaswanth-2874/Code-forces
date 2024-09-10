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
    int n, m;
    cin>>n>>m;
    vector<vector<int>> cardNumbers = vector<vector<int>> (m, vector<int> (n));
    // vector<vector<int>> prefixSum = vector<vector<int>> (m, vector<int> (n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>cardNumbers[j][i];
        }
    }

    int res = 0;

    for(int i = 0; i < m; i++) {
        sort(full(cardNumbers[i]));
        int value = 1 - n;
        for(int j = 0; j < n; j++) {
            res += value*cardNumbers[i][j];
            value += 2;
        }
    }

    cout<<res<<endl;

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
