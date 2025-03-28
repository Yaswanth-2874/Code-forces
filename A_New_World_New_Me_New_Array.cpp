#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, target, maxVal;
        cin >> n >> target >> maxVal;

        target = abs(target);
        int maxi = maxVal * n;
        if(target > maxi)
            /* Print number*/ {
                cout<<-1<<endl;
                return;
            }
        /* Print number*/ {
            cout<<(target + maxVal-1)/maxVal<<endl;
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
