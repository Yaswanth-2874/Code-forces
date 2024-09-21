#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

// 2 3 1 5

// 2 3 6 - 1
// 1 1 3 6 - 1
// 3 8 - 2
// 1 1 1 8 - 2
// 11 - 3
class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < k; i++) {
            int cut;
            cin >> cut;
            pq.push(cut);
        }
        int moves = 0;

        while(pq.size() > 1) {
            int top = pq.top();
            pq.pop();
            int cuts = max(0, top - 1);
            moves += cuts;
            int attaches = cuts + 1;
            moves += attaches;
        }
        cout<<moves<<endl;
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

