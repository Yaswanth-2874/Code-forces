#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int x, y, z, a, b, c;
        cin >> x >> y >> z >> a >> b >> c;

        if(z > c) {
            y += z-c;
        }
        if(y > b) {
            x += y-b;
        }

        int ans = min(a,x) + min(b,y) + min(c,z);
        cout<<ans<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
