#include <bits/stdc++.h>
using namespace std;

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

//Please no edge cases, this seems easy

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        if(k >= n)
            pn(1);

        int ans = n;

        for(int i = 1; i*i <= n; i++) {
            if(n % i == 0) {
                // cout<<"Need "<<i<<" boxes of "<<n/i<<" shovels"<<endl;
                if(i <= k)
                    ans = min(n/i, ans);
                if(n/i <= k)
                    ans = min(i, ans);
            }
        }

        cout<<ans<<endl;
        
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