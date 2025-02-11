#include <bits/stdc++.h>
#define int long long
using namespace std;


class Solution {
    int n;
    int findMiddlePoints(vector<int>& x) {
        sort(begin(x), end(x));
        if(n % 2 == 1) {
            return 1;
        }

        return x[n/2] - x[n/2 - 1] + 1;
    }
    public:
    void solve() {
        cin >> n;

        vector<int> x(n), y(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        /* Print number*/ {
            cout<<findMiddlePoints(x)* findMiddlePoints(y)<<endl;
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
