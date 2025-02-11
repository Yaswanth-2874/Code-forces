#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);

        for (auto& input : v) {
            cin >> input;
        }

        if(n == k) {
            int val = 1;
            for(int i = 1; i < n; i+=2) {
                if(v[i] != val)
                /* Print number*/ {
                    cout<<val<<endl;
                    return;
                }
                val++;
            }
            /* Print number*/ {
                cout<<val<<endl;
                return;
            }
        }
    
        int maxSize = n - (k - 1);

        //second subarray can lie only between [1, 1+size]
        for(int i = 1; i < 1+maxSize; i++) {
            if(v[i] != 1)
            /* Print number*/ {
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
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
