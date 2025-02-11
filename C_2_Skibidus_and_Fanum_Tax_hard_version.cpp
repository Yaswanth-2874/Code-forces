#include <bits/stdc++.h>
#define int long long
using namespace std;

// optimally b[j] - a[i] value must be as close to prev as possible

class Solution {
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (auto& input : a) {
            cin >> input;
        }

        vector<int> b(m);
        for (auto& input : b) {
            cin >> input;
        }

        sort(begin(b), end(b));

        a[0] = min(a[0], b[0] - a[0]); // first number should be as low as possible
        // next number should be just slightly higher or equal to first number
        int prev = a[0];

        for(int i = 1; i < n; i++) {
            int target = prev + a[i];
            int index = lower_bound(begin(b), end(b), target) - begin(b);
            if(index != m) {
                if(a[i] >= prev)
                    a[i] = min(a[i], b[index] - a[i]);
                else
                    a[i] = b[index] - a[i];
            }

            if(a[i] < prev) {
                /* Print no*/ {
                    cout<<"NO\n";
                    return;
                }
            }
            prev = a[i];
        }

        /* Print yes*/ {
            cout<<"YES\n";
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
