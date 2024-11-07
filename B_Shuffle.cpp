#include <bits/stdc++.h>
using namespace std;

// Interval question 
// initially, interval is of size 1 only
// Compare their interval with the currentInterval, if they have common, merge it
// This should work, each query is answerd in o(1) time

class Solution {
    public:
    void solve() {
        int n, x, m;
        cin >> n >> x >> m;

        int leftInterval = x, rightInterval = x;

        while(m--) {
            int left, right;
            cin >> left >> right;
            if(left > rightInterval)
                continue;
            if(right < leftInterval)
                continue;
            leftInterval = min(left, leftInterval);
            rightInterval = max(right, rightInterval);
        }

        cout<<rightInterval - leftInterval + 1<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

