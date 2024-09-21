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
        int a, b, c;
        cin >> a >> b >> c;

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int t = 5;
        while (t--) {
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }
        int ans = 1;
        t = 3;

        while(t--) {
            ans *= pq.top();
            pq.pop();
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

