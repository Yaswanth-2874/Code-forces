#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int x, y;
        cin >> x >> y;

        if(x < y) {
            swap(x, y);
        }

        int ans = (x + y);
        x -= y+1;
        y = 0;
        if(x > 0) {
            ans += x;
        }

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
