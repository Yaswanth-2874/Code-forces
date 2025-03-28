#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        // ill only try to print n and n-1
        if(k % 2) {
            for(int i = 1; i <= n; i++) {
                if(i == n)
                    cout<<n-1<<" ";
                else
                    cout<<n<<" ";
            }
        } else {
            for(int i = 1; i <= n; i++) {
                if(i == n-1)
                    cout<<n<<" ";
                else
                    cout<<n-1<<" ";
            }
        }
        cout<<endl;
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
