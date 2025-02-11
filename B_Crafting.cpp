#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& input : a) {
            cin >> input;
        }
        int maxNeeded = 0;
        int extra = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            maxNeeded = max(maxNeeded, input - a[i]);
            if(a[i] >= input);
                extra = min(extra, a[i] - input);
        }

        if(extra >= maxNeeded)
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
