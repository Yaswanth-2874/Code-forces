#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        double l, r, d, u;
        cin >> l >> r >> d >> u;

        if(l == r && r ==d && r == u)
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
