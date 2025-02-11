#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    int n, k;
    int findAns(int left, int right) {
        if(left > right)
            return 0;

        int mid = left + (right - left)/2;
        int size = right - left + 1;
        if(size < k)
            return 0;

        if(size % 2 == 0)
            return findAns(left, mid) + findAns(mid+1, right);
        return mid + findAns(left, mid-1) + findAns(mid+1, right);
    }
 
    public:
    void solve() {
        cin >> n >> k;
        int luck = 0;
        int d = 1;
        // {
        //     cout<<findAns(1, n)<<endl;
        //     return;
        // }
        
        int nCopy = n;
        int val = -1;
        val = (nCopy + 1);

        while(nCopy > 0) {
            if(nCopy % 2ll == 1) {
                luck += d * val;
            }
            if(nCopy/2ll < k) {
                break;
            }
            nCopy/=2ll;
            d *= 2ll;
        }

        cout<<luck/2<<endl;
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
