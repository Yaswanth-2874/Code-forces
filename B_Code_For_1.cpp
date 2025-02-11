#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    bool isOne(int n, int target, int left, int right) {
        if(left == right)
            return n%2;
        int mid = left + (right - left)/2;
        if(mid == target)
            return n%2;
        if(target > mid)
            return isOne(n/2, target, mid+1, right);
        return isOne(n/2, target, left, mid-1);
    }
    public:
    void solve() {
        int n, l, r;
        cin >> n >> l >> r;
        int count = 0;
        int logV = log2l(n);
        int size = (1ll << (logV + 1ll)) - 1ll;

        for(int i = l; i <= r; i++) {
            count += isOne(n, i, 1, size);
        }

        /* Print number*/ {
            cout<<count<<endl;
            return;
        }
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
