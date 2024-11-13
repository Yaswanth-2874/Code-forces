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

// ai = b(i) + c for 0 based index
// require mex


class Solution {
    public:
    void solve() {
        int n, b, c;
        cin >> n >> b >> c;

        if(c > n-1)
            pn(n);

        if(b == 0) {
            // ALl terms are equal
            if(c == n-1)
                pn(n-1);
            if(c == n-2)
                pn(n-1);
            pn(-1);
        }
        
        int t = (n - 1 - c)/b + 1;
        pn(n - t);
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
