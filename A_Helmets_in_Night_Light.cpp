#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;


class Solution {
    public:
    void solve() {
        int n, p;
        cin>>n>>p;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> share(n), cost(n);
        input(share);
        input(cost);
        int ans = p;

        for(int i = 0; i < n; i++) {
            pq.push({cost[i], share[i]});
        }

        for(int i = 1; i < n; i++) {
            if(p <= pq.top().first) {
                ans += p;
            } else if(pq.top().second > 0) {
                auto [costI, shareI] = pq.top();
                pq.pop();
                ans += costI;
                if(--shareI > 0)
                    pq.push({costI, shareI});
            } else {
                pq.pop();
                i--;
            }
        }
        cout<<ans<<endl;
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
