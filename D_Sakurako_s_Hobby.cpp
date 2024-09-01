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
        nums[i] -= 1;
    }

    string black;
    cin>>black;
    vector<int> ans(n);
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        int zeroCount = 0;
        if (!visited[i]) {
            vector<int> cycle;
            int current = i;
            while(!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                current = nums[current];
            }
            for(int idx : cycle) {
                if (black[idx] == '0') {
                    zeroCount++;
                }
            }
            for (int j : cycle) {
                ans[j] = zeroCount;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

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
