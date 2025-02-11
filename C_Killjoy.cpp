#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        int correct = 0;
        int sum = 0;

        for (auto& input : v) {
            cin >> input;
            correct += input == x;
            sum += input;
        }

        if(correct == n) {
            /* Print number*/ {
                cout<<0<<endl;
                return;
            }
        }
        if(correct >= 1 || sum == x*n) {
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
