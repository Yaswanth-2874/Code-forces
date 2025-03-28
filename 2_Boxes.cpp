#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, m, k;
        cin >> n >> m >> k;

        int diff = abs(n - m);
        int reqd = abs(diff - k);

        if(reqd % 2 != 0)
            /* Print number*/ {
                cout<<-1<<endl;
                return;
            }
        /* Print number*/ {
            cout<<reqd/2<<endl;
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
