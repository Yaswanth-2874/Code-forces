#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int x, y;
        cin >> x >> y;

        if(x == y-1 || (x >= y && (x-y)%9 == 8))
            /* Print yes*/ {
                cout<<"YES\n";
                return;
            }
        /* Print no*/ {
            cout<<"NO\n";
            return;
        }
        
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
