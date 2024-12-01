#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}

class Solution {
    int query(int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    public:
    void solve() {
        int n, t;
        cin >> n >> t;

        int k;
        cin >> k;

        int left = 1, right = n;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int givenSum = query(1, mid);
            int expectedSum = mid;

            int zeroesPresent = expectedSum - givenSum;
            if(zeroesPresent >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        printAns(right+1);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

