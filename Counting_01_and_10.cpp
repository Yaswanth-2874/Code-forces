#include <bits/stdc++.h>
#define int long long
using namespace std;


class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        int ans = 0;
        int zeroes = 0, ones = n;
        while(zeroes <= ones) {
            ans += (ones * zeroes) + 1;
            ones--;
            zeroes++;
        }
        cout<<ans<<endl;
        
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
