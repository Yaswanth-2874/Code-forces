#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, d;
        cin >> n >> d;
        // sum of all digits in n! * d

        vector<int> ans(1, 1);
        if(d % 3 == 0 || n >= 3)
            ans.push_back(3);
        if(d == 5)
            ans.push_back(5);
        if(n >= 3 || d == 7)
            ans.push_back(7);
        if(n >= 6)
            ans.push_back(9);
        else {
            int fact = 1;
            for(int i = 1; i <= n; i++) {
                fact *= i;
            }
            if(fact * d % 9 == 0)
                ans.push_back(9);
        }

        /* Print array*/ {
            for(auto& val : ans) {
                cout << val << " ";
            }
            cout << endl;
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
