#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, x;
        cin >> n >> x;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            sum += num;
        }

        if(sum % n == 0 && sum/n == x)
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
